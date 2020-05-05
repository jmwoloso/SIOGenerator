#include <stdio.h>
#include <string.h>
#include "constsw.h"
#include "structsw.h"
#include "protosw.h"
int rd_flds(inp_txt,num_flds,pt1,db_spec,err_buf,num_sep,ptr)
unsigned char inp_txt[];               
int           *num_flds;               
unsigned char *pt1;                    
FIL_SPC       *db_spec;                
char          err_buf[];               
int           *num_sep;                
unsigned char **ptr;                   
{
  int no_error = 1;                    
  if (!(no_error = ((*num_sep = cnt_sep(inp_txt,ptr)) >= NUM_SEP)))
    sprintf(err_buf,"%s","Field delimiter(s) missing");
  else if (!(no_error = (sscanf(inp_txt,"%d %s %d %s",
	     &DB_SPEC.idx,DB_SPEC.type,&DB_SPEC.lnth,DB_SPEC.order) == 4)))
    sprintf(err_buf,"%s","Illegal number of fields or bad data in fields");
  else if (fld_typ(SPC_OPT,DB_SPEC.type))
  {
    if (strcmp(DB_SPEC.type,XYZIX))
      no_error = (sscanf(pt1,"%ld %ld %ld %ld %ld %ld %ld %ld %ld %d %d",
			     &DB_SPEC.lower.l[0],&DB_SPEC.lower.l[1],
			     &DB_SPEC.lower.l[2],&DB_SPEC.upper.l[0],
			     &DB_SPEC.upper.l[1],&DB_SPEC.upper.l[2],
			     &DB_SPEC.intrv.l[0],&DB_SPEC.intrv.l[1],
			     &DB_SPEC.intrv.l[2],&DB_SPEC.num_dec,
			     &DB_SPEC.rpt_lmt) == 11);
    else
      no_error = (sscanf(pt1,"%ld %ld %ld %ld %ld %ld %d %d",
			     &DB_SPEC.lower.l[0],&DB_SPEC.lower.l[1],
			     &DB_SPEC.upper.l[0],&DB_SPEC.upper.l[1],
			     &DB_SPEC.intrv.l[0],&DB_SPEC.intrv.l[1],
			     &DB_SPEC.num_dec,&DB_SPEC.rpt_lmt) == 8);
    if (!no_error)
      sprintf(err_buf,"%s","Illegal number of fields or bad data in fields");
  }
  if (no_error && !fld_typ(SPC_OPT,DB_SPEC.type))
  {
    if (fld_typ(FLT_OPT,DB_SPEC.type))
      no_error = (sscanf(pt1,"%Le %Le %Le %d %d",
			 &DB_SPEC.lower.d,&DB_SPEC.upper.d,
			 &DB_SPEC.intrv.d,&DB_SPEC.num_dec,
			 &DB_SPEC.rpt_lmt) == 5);
    else if (strcmp(DB_SPEC.type,XYZAD))
      no_error = (sscanf(pt1,"%ld %ld %ld %d %d",
			 &DB_SPEC.lower.l[0],&DB_SPEC.upper.l[0],
			 &DB_SPEC.intrv.l[0],&DB_SPEC.num_dec,
			 &DB_SPEC.rpt_lmt) == 5);
    else if (!strcmp(DB_SPEC.type,XYZAD))
      no_error = (sscanf(pt1,"%x %x %x %d %d",
			 &DB_SPEC.lower.l[0],&DB_SPEC.upper.l[0],
			 &DB_SPEC.intrv.l[0],&DB_SPEC.num_dec,
			 &DB_SPEC.rpt_lmt) == 5);
    if (!no_error)
      sprintf(err_buf,"%s","Illegal number of fields or bad data in fields");
  }
  if (no_error)
  {
    if (fld_typ(FLT_OPT,DB_SPEC.type) &&
	!(no_error = IN_RANG(0L,MAX_FLT,DB_SPEC.num_dec)))
      sprintf(err_buf,"%s","Illegal number of decimal places");
    else if (!fld_typ(FLT_OPT,DB_SPEC.type) &&
	     !(no_error = IN_RANG(0L,MAX_DEC,DB_SPEC.num_dec)))
      sprintf(err_buf,"%s","Illegal number of decimal places");
    else if (!(no_error = (DB_SPEC.rpt_lmt > 0L && DB_SPEC.rpt_lmt <= MAX_RPT)))
      sprintf(err_buf,"%s","Illegal repeat count");
  }
  return(no_error);
}
