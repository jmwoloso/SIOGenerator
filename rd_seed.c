#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <ctype.h>
#include "constsw.h"
#include "structsw.h"
#include "protosw.h"
int rd_seed(ptr,num_flds,num_sep,db_spec,err_buf,no_mem_err)
unsigned char *ptr;                    
int           *num_flds;               
int           num_sep;                 
FIL_SPC       *db_spec;                
char          err_buf[];               
int           *no_mem_err;             
{
  int           no_error = 1;          
  int           idx = 0;               
  unsigned char *pt1,*pt2;             
  if (!strcmp(DB_SPEC.type,XYZBO))
  {
    if (no_error = (num_sep <= NUM_SEP + 5))
      for (idx = 0; idx <= num_sep - NUM_SEP && no_error; idx++)
      {
	sscanf(ptr,"%s",err_buf);      
	if (no_error = (int)(ptr = strchr(ptr,')')))
	  {
	  ++ptr;                       
	  if (*ptr == ')')             
	    ++ptr;
	  if (no_error = (isspace(*ptr) || !*ptr))
	  {
	    if (no_error = (int)(pt1 = strchr(err_buf,CLN_SEP)))
	    {
	      *pt1++ = BLNK1;          
	      if (sscanf(err_buf,"%d",&DB_SPEC.seed.f[idx]))
	      {
		--DB_SPEC.seed.f[idx]; 
		pt2 = pt1;
		if (no_error = (int)(pt2 = strchr(pt1,DSH_SEP)))
		{
		  *pt2++ = BLNK1;
		  if (sscanf(pt1,"%d",&DB_SPEC.lower.f[idx]))
		  {
		    --DB_SPEC.lower.f[idx];
		    pt1 = pt2;
		    if (no_error = (int)(pt2 = strchr(pt1,'(')))
		    {
		      *pt2++ = BLNK1;
		      if (sscanf(pt1,"%d",&DB_SPEC.upper.f[idx]))
		      {
			--DB_SPEC.upper.f[idx];
			pt1 = strchr(pt2,')') + 1;
			if (*pt1 == ')')
			  ++pt1;
			if (pt1 - pt2 == 1)
			  DB_SPEC.intrv.c[idx] = NUL_SEP;
			else if (pt1 - pt2 == 2)
			  DB_SPEC.intrv.c[idx] = *pt2;
			else
			  no_error = 0;
		      }
		    }
		  }
		}
	      }
	    }
	  }
	}
      }
  }
  else if (!strcmp(DB_SPEC.type,XYZIX))
    no_error = (sscanf(ptr,"%ld %ld %s",
		&DB_SPEC.seed.l[0],&DB_SPEC.seed.l[1],DB_SPEC.tim_zon) == 3);
  else if (fld_typ(SPC_OPT,DB_SPEC.type))
    no_error = (sscanf(ptr,"%ld %ld %ld",
		       &DB_SPEC.seed.l[0],&DB_SPEC.seed.l[1],
		       &DB_SPEC.seed.l[2]) == 3);
  else if (strcmp(DB_SPEC.type,XYZAD))
    no_error = (sscanf(ptr,"%ld",&DB_SPEC.seed.l[0]) == 1);
  else
    no_error = (sscanf(ptr,"%x",&DB_SPEC.seed.l[0]) == 1);
  if (!no_error)
    sprintf(err_buf,"%s","Missing/illegal/too many seed value(s)");
  else if (strcmp(DB_SPEC.type,XYZYF) && strcmp(DB_SPEC.type,XYZBO))
  {
    if (no_error = IN_RANG(0L,MAX_RND,DB_SPEC.seed.l[0]))
      if (fld_typ(SPC_OPT,DB_SPEC.type))
	if (no_error = IN_RANG(0L,MAX_RND,DB_SPEC.seed.l[1]))
      if (strcmp(DB_SPEC.type,XYZIX))
	    no_error = IN_RANG(0L,MAX_RND,DB_SPEC.seed.l[2]);
    if (!no_error)
      sprintf(err_buf,"%s","Seed value is outside legal range");
    else if (fld_typ(FLT_OPT,DB_SPEC.type))
    {
      if (DB_SPEC.order[0] == RAN_ORD) 
	DB_SPEC.seed.l[0] *= -1;       
      DB_SPEC.seed.l[1] = DB_SPEC.seed.l[0];
      DB_SPEC.seed.l[2] = DB_SPEC.seed.l[0];
    }
  }
  else if (strcmp(DB_SPEC.type,XYZBO))
  {
    --DB_SPEC.seed.l[0];
    if (!(no_error = IN_RANG(0L,(long)(*num_flds-1),DB_SPEC.seed.l[0])))
      sprintf(err_buf,"%s","Illegal field index for duplicate field");
    else if (strcmp(db_spec->fld_spc[(int)DB_SPEC.seed.l[0]].type,XYZYF))
    {
      if (db_spec->fld_spc[(int)DB_SPEC.seed.l[0]].sav_val == NULL)
	if (!(*no_mem_err = ((db_spec->fld_spc[(int)DB_SPEC.seed.l[0]].sav_val =
			(unsigned char *)malloc(MAX_FLD *
			 sizeof(unsigned char))) != NULL)))
	  sprintf(err_buf,"%s","Unable to allocate memory in rd_seed()");
    }
    else
      DB_SPEC.seed.l[0] = db_spec->fld_spc[(int)DB_SPEC.seed.l[0]].seed.l[0];
  }
  else
  {
    for (idx = 0; idx <= num_sep - NUM_SEP && no_error; idx++)
    {
      if (!(no_error = IN_RANG(0L,(long)(*num_flds-1),DB_SPEC.seed.f[idx])))
	sprintf(err_buf,"%s","Illegal field index for concatenated field");
      else if (strcmp(db_spec->fld_spc[(int)DB_SPEC.seed.f[idx]].type,XYZYF))
      {
	if (db_spec->fld_spc[(int)DB_SPEC.seed.f[idx]].sav_val == NULL)
	  if (!(*no_mem_err =
		((db_spec->fld_spc[(int)DB_SPEC.seed.f[idx]].sav_val =
			       (unsigned char *)malloc(MAX_FLD *
				sizeof(unsigned char))) != NULL)))
	    sprintf(err_buf,"%s","Unable to allocate memory in rd_seed()");
      }
      else
	DB_SPEC.seed.f[idx] =
		       db_spec->fld_spc[(int)DB_SPEC.seed.f[idx]].seed.l[0];
      if (no_error)
	if (!(no_error = (DB_SPEC.lower.f[idx] <= DB_SPEC.upper.f[idx] &&
			  DB_SPEC.lower.f[idx] >= 0                    &&
			  DB_SPEC.upper.f[idx] <
			  db_spec->fld_spc[(int)DB_SPEC.seed.f[idx]].lnth)))
	  sprintf(err_buf,"%s","Illegal column range");
    }
    if (no_error && idx < 6)
      DB_SPEC.seed.f[idx] = - 1;       
  }
  return(no_error);
}
