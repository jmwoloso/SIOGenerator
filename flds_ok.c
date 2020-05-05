#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include "constsw.h"
#include "structsw.h"
#include "protosw.h"
int flds_ok(fpinp,fname,tim_zons,db_spec,num_flds,decoded,tim_lmts,tim_flds,
	    cst_flds,fptrl,uni_flds)
FILE          **fpinp;                 
unsigned char fname[];                 
unsigned char tim_zons[][4];           
FIL_SPC       *db_spec;                
int           *num_flds;               
unsigned char **decoded;               
TIM_REC       tim_lmts[];              
int           *tim_flds;               
int           *cst_flds;               
FILE          **fptrl;                 
int           *uni_flds;               
{
  extern int line_num;                 
  long          dummy = 1;             
  char          err_buf[50];           
  unsigned char inp_txt[BUFSIZ];       
  int           no_error;              
  int           no_mem_err = 1;        
  int           num_sep;               
  unsigned char *ptr,*pt1;             
  int           ret_flag = 1;          
  while (no_mem_err && fgets(inp_txt,BUFSIZ,*fpinp))
  {
    ++line_num;
    if (not_blnk(inp_txt))
    {                                  
      skp_fld(inp_txt,&pt1);           
      DB_SPEC.sav_val = NULL;          
      if (no_error = rd_flds(inp_txt,num_flds,pt1,db_spec,err_buf,&num_sep,
			       &ptr))  
    if (strcmp(DB_SPEC.type,XYZIN) && !fld_typ(CST_OPT,DB_SPEC.type))
	  no_error = rd_seed(ptr,num_flds,num_sep,db_spec,err_buf,&no_mem_err);
	else if (!(no_mem_err = ((decoded[*num_flds] = (unsigned char *)
                  calloc(XYZIN_LN,sizeof(unsigned char))) != NULL)))
	  sprintf(err_buf,"%s","Unable to allocate memory in flds_ok");
	else                           
      ;
      if (!no_error || !no_mem_err)
	PRINT_ERR(err_buf);
      else
      {                                
	DB_SPEC.rpt_idx = DB_SPEC.rpt_lmt;
	if (!(no_error = chk_nlt(num_flds,db_spec,err_buf)))
	  PRINT_ERR(err_buf);
    else if (strcmp(DB_SPEC.type,XYZYF) && strcmp(DB_SPEC.type,XYZNK) &&
         strcmp(DB_SPEC.type,XYZBO))
	{                              
	  if (!(no_error = ck_olui(num_flds,tim_zons,db_spec,err_buf)))
	    PRINT_ERR(err_buf);
	  else
	  {
	    if (DB_SPEC.order[0] == UNI_ORD)
	    {                          
	      no_error = set_unif(*num_flds,db_spec,uni_flds);
	    }
	    if (no_error)
	    {
	      if (fld_typ(FLT_OPT,DB_SPEC.type))
	      {
		if (DB_SPEC.lower.d == 0 && DB_SPEC.upper.d == 0)
		{
		  DB_SPEC.upper.d = LDBL_MAX / 100;
		  if (DB_SPEC.intrv.d == 0)
		    ++DB_SPEC.intrv.d;
		}
	      }
	      else if (DB_SPEC.lower.l[0] == 0 && DB_SPEC.upper.l[0] == 0)
		if (!fld_typ(SPC_OPT,DB_SPEC.type))
		  set_bnds(DB_SPEC.option,&DB_SPEC.lower.l[0],
			   &DB_SPEC.upper.l[0],&DB_SPEC.intrv.l[0]);
        else if (strcmp(DB_SPEC.type,XYZIX))
		{
		  if (DB_SPEC.lower.l[0] == 0 && DB_SPEC.upper.l[0] == 0 &&
		      DB_SPEC.lower.l[1] == 0 && DB_SPEC.upper.l[1] == 0 &&
		      DB_SPEC.lower.l[2] == 0 && DB_SPEC.upper.l[2] == 0)
		  {                    
            set_bnds(OXYZM6,&DB_SPEC.lower.l[0],&DB_SPEC.upper.l[0],
			     &dummy);
            set_bnds(OXYZHR,&DB_SPEC.lower.l[1],&DB_SPEC.upper.l[1],
			     &dummy);
		    if (DB_SPEC.intrv.l[0] == 0 && DB_SPEC.intrv.l[1] == 0)
              set_bnds(OXYZP1,&DB_SPEC.lower.l[2],&DB_SPEC.upper.l[2],
			       &DB_SPEC.intrv.l[2]);
		    else
              set_bnds(OXYZP1,&DB_SPEC.lower.l[2],&DB_SPEC.upper.l[2],
			       &dummy);
		  }
		}
		else
		{
		  if (DB_SPEC.lower.l[0] == 0 && DB_SPEC.upper.l[0] == 0 &&
		      DB_SPEC.lower.l[1] == 0 && DB_SPEC.upper.l[1] == 0)
		  {                    
            set_bnds(OXYZM6,&DB_SPEC.lower.l[0],&DB_SPEC.upper.l[0],
			     &dummy);
		    if (DB_SPEC.intrv.l[0] == 0)
              set_bnds(OXYZHR,&DB_SPEC.lower.l[1],&DB_SPEC.upper.l[1],
			       &DB_SPEC.intrv.l[1]);
		    else
              set_bnds(OXYZHR,&DB_SPEC.lower.l[1],&DB_SPEC.upper.l[1],
			       &dummy);
		  }
		}
	      if (DB_SPEC.sav_val == NULL && DB_SPEC.rpt_lmt > 1)
		if (!(no_mem_err = ((DB_SPEC.sav_val =
				    (unsigned char *)calloc(MAX_FLD,
				     sizeof(unsigned char))) != NULL)))
		  PRINT_ERR("Unable to allocate memory in flds_ok()");
	      if ((fld_typ(DAT_OPT,DB_SPEC.type) ||
		   fld_typ(TIM_OPT,DB_SPEC.type) ||
		   fld_typ(SPC_OPT,DB_SPEC.type)) && no_mem_err)
	      {                        
	      }
	      else if (fld_typ(RAN_OPT,DB_SPEC.type) && no_mem_err)
		if (!(no_error = chk_ran(num_flds,db_spec,err_buf)))
		  PRINT_ERR(err_buf);
	    }
	  }
	}
      }
      if (ret_flag = (ret_flag && no_error && no_mem_err))
      {                                
	no_mem_err = srt_flds(db_spec,decoded,num_flds);
      }
    }
  }
  if (ret_flag && no_mem_err)
    if (!(ret_flag = in_seq(db_spec,*num_flds)))
      printf("\nField numbers are not sequential in specifications file\n");
  closfils(fpinp);
  return(ret_flag && no_mem_err);
}
