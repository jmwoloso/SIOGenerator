#include <stdio.h>
#include <string.h>
#include <float.h>
#include <ctype.h>
#include "constsw.h"
#include "structsw.h"
#include "protosw.h"
int ck_olui(num_flds,tim_zons,db_spec,err_buf)
int           *num_flds;               
unsigned char tim_zons[][4];           
FIL_SPC       *db_spec;                
char          err_buf[];               
{
  int no_error = 1;                    
  int idx;                             
  if (!(no_error = ((DB_SPEC.order[0] = toupper(DB_SPEC.order[0])) == RAN_ORD
		     || DB_SPEC.order[0] == SEQ_ORD
		     || DB_SPEC.order[0] == UNI_ORD)))
    sprintf(err_buf,"%s","Illegal order type");
  else if (!(no_error = (fld_typ(DEC_OPT,DB_SPEC.type)   ||
			 fld_typ(FLT_OPT,DB_SPEC.type)   ||
			 (!fld_typ(DEC_OPT,DB_SPEC.type) &&
			  !fld_typ(FLT_OPT,DB_SPEC.type) &&
			  DB_SPEC.lower.l[0] >= 0))))
    sprintf(err_buf,"%s","Negative bounds legal only for numeric fields");
  else if (!(no_error = (strcmp(DB_SPEC.type,INTER) == 0  ||
			 fld_typ(FLT_OPT,DB_SPEC.type)    ||
			 (strcmp(DB_SPEC.type,INTER)      &&
			  DB_SPEC.num_dec == 0))))
    sprintf(err_buf,"%s","Decimal places cannot be non-zero");
  else if (!(no_error = (!fld_typ(DEC_OPT,DB_SPEC.type)                ||
			 (fld_typ(DEC_OPT,DB_SPEC.type)                &&
			  IN_RANG(-MAX_RND,MAX_RND,DB_SPEC.lower.l[0]) &&
			  IN_RANG(-MAX_RND,MAX_RND,DB_SPEC.upper.l[0])))))
    sprintf(err_buf,"%s","Illegal range");
  else if (!(no_error = (DB_SPEC.order[0] != UNI_ORD) ||
			(DB_SPEC.order[0] == UNI_ORD  &&
			 !strcmp(DB_SPEC.type,INTER))))
    sprintf(err_buf,"%s","Unique values valid only for numeric type");
  else if (!(no_error = (DB_SPEC.order[0] != UNI_ORD) ||
			(DB_SPEC.order[0] == UNI_ORD  &&
			db_spec->num_recs <= (DB_SPEC.upper.l[0] -
					      DB_SPEC.lower.l[0]))))
    sprintf(err_buf,"%s","Range too small for unique field");
  else if (!(no_error = (DB_SPEC.order[0] != UNI_ORD) ||
			(DB_SPEC.order[0] == UNI_ORD && DB_SPEC.rpt_lmt == 1)))
    sprintf(err_buf,"%s","Repeat count for unique fields must be 1");
  else if (!fld_typ(SPC_OPT,DB_SPEC.type) && !fld_typ(FLT_OPT,DB_SPEC.type))
  {
    if (!(no_error = ((DB_SPEC.order[0] == SEQ_ORD  &&
		      ((DB_SPEC.intrv.l[0] == 0     &&
			DB_SPEC.lower.l[0] == 0     &&
			DB_SPEC.upper.l[0] == 0)    ||
			DB_SPEC.intrv.l[0] != 0))   ||
		       DB_SPEC.order[0] == RAN_ORD  ||
		       DB_SPEC.order[0] == UNI_ORD)))
      sprintf(err_buf,"%s","Zero interval");
    else if (!(no_error = (DB_SPEC.order[0] != RAN_ORD ||
			  (DB_SPEC.order[0] == RAN_ORD &&
			   DB_SPEC.intrv.l[0] >= 0))))
      sprintf(err_buf,"%s","Negative interval illegal for random order");
    else if (!(no_error = INTV_OK(DB_SPEC.lower.l[0],DB_SPEC.upper.l[0],
				  DB_SPEC.intrv.l[0])))
      sprintf(err_buf,"%s","Illegal range");
  }
  else if (fld_typ(FLT_OPT,DB_SPEC.type))
  {
    if (!(no_error = ((DB_SPEC.order[0] == SEQ_ORD  &&
		      ((DB_SPEC.intrv.d == 0        &&
			DB_SPEC.lower.d == 0        &&
			DB_SPEC.upper.d == 0)       ||
			DB_SPEC.intrv.d != 0))      ||
		       DB_SPEC.order[0] == RAN_ORD  ||
		       DB_SPEC.order[0] == UNI_ORD)))
      sprintf(err_buf,"%s","Zero interval");
    else if (!(no_error = (DB_SPEC.order[0] != RAN_ORD ||
			  (DB_SPEC.order[0] == RAN_ORD &&
			   DB_SPEC.intrv.d >= 0))))
      sprintf(err_buf,"%s","Negative interval illegal for random order");
    else if (!(no_error = (DB_SPEC.lower.d > 0                       &&
			   DB_SPEC.lower.d >= LDBL_MIN * 100)        ||
			  (DB_SPEC.lower.d < 0                       &&
			   (DB_SPEC.lower.d * -1) >= LDBL_MIN * 100) ||
			  DB_SPEC.lower.d == 0))
      sprintf(err_buf,"%s","Lower limit is too small");
    else if (!(no_error = (DB_SPEC.upper.d > 0                       &&
			   DB_SPEC.upper.d >= LDBL_MIN * 100)        ||
			  (DB_SPEC.upper.d < 0                       &&
			   (DB_SPEC.upper.d * -1) >= LDBL_MIN * 100) ||
			  DB_SPEC.upper.d == 0))
      sprintf(err_buf,"%s","Upper limit is too small");
    else if (!(no_error =
	       IN_RANG(-LDBL_MAX/100,LDBL_MAX/100,DB_SPEC.lower.d) &&
	       IN_RANG(-LDBL_MAX/100,LDBL_MAX/100,DB_SPEC.upper.d)))
      sprintf(err_buf,"%s","Illegal range");
    else if (!(no_error = INTV_OK(DB_SPEC.lower.d,DB_SPEC.upper.d,
				  DB_SPEC.intrv.d)))
      sprintf(err_buf,"%s","Illegal range");
    else if (DB_SPEC.order[0] == RAN_ORD)
      DB_SPEC.intrv.d = DB_SPEC.upper.d - DB_SPEC.lower.d;
  }
  else if (strcmp(DB_SPEC.type,XYZIX))
  {
    if (!(no_error = ((DB_SPEC.order[0] == SEQ_ORD &&
		      ((DB_SPEC.intrv.l[0] == 0    &&
			DB_SPEC.lower.l[0] == 0    &&
			DB_SPEC.upper.l[0] == 0    &&
			DB_SPEC.intrv.l[1] == 0    &&
			DB_SPEC.lower.l[1] == 0    &&
			DB_SPEC.upper.l[1] == 0    &&
			DB_SPEC.intrv.l[2] == 0    &&
			DB_SPEC.lower.l[2] == 0    &&
			DB_SPEC.upper.l[2] == 0)   ||
		      (DB_SPEC.intrv.l[0] != 0     ||
		       DB_SPEC.intrv.l[1] != 0     ||
		       DB_SPEC.intrv.l[2] != 0)))  ||
		       DB_SPEC.order[0] == RAN_ORD ||
		       DB_SPEC.order[0] == UNI_ORD)))
      sprintf(err_buf,"%s","Zero interval");
    else if (!(no_error = (DB_SPEC.order[0] != RAN_ORD ||
			  (DB_SPEC.order[0] == RAN_ORD &&
			   DB_SPEC.intrv.l[0] >= 0     &&
			   DB_SPEC.intrv.l[1] >= 0     &&
			   DB_SPEC.intrv.l[2] >= 0))))
      sprintf(err_buf,"%s","Negative interval illegal for random order");
    else if (!(no_error = (INTV_OK(DB_SPEC.lower.l[0],DB_SPEC.upper.l[0],
				   DB_SPEC.intrv.l[0])
      ||  INTV_OK(DB_SPEC.lower.l[1],DB_SPEC.upper.l[1],DB_SPEC.intrv.l[1])
      ||  INTV_OK(DB_SPEC.lower.l[2],DB_SPEC.upper.l[2],DB_SPEC.intrv.l[2]))))
      sprintf(err_buf,"%s","Illegal range");
  }
  else
  {
    if (!(no_error = ((DB_SPEC.order[0] == SEQ_ORD &&
		      ((DB_SPEC.intrv.l[0] == 0    &&
			DB_SPEC.lower.l[0] == 0    &&
			DB_SPEC.upper.l[0] == 0    &&
			DB_SPEC.intrv.l[1] == 0    &&
			DB_SPEC.lower.l[1] == 0    &&
			DB_SPEC.upper.l[1] == 0)   ||
		      (DB_SPEC.intrv.l[0] != 0     ||
		       DB_SPEC.intrv.l[1] != 0)))  ||
		       DB_SPEC.order[0] == RAN_ORD ||
		       DB_SPEC.order[0] == UNI_ORD)))
      sprintf(err_buf,"%s","Zero interval");
    else if (!(no_error = (DB_SPEC.order[0] != RAN_ORD ||
			  (DB_SPEC.order[0] == RAN_ORD &&
			   DB_SPEC.intrv.l[0] >= 0     &&
			   DB_SPEC.intrv.l[1] >= 0))))
      sprintf(err_buf,"%s","Negative interval illegal for random order");
    else if (!(no_error = (INTV_OK(DB_SPEC.lower.l[0],DB_SPEC.upper.l[0],
				   DB_SPEC.intrv.l[0])
      ||  INTV_OK(DB_SPEC.lower.l[1],DB_SPEC.upper.l[1],DB_SPEC.intrv.l[1]))))
	sprintf(err_buf,"%s","Illegal range");
    else
    {
      for (idx = 0; idx < MAX_ZON; idx++)
	if (!strcmp(tim_zons[idx],DB_SPEC.tim_zon))
	  break;
      if (!(no_error = (idx < MAX_ZON)))
	sprintf(err_buf,"%s","Illegal field fill type");
    }
  }
  return(no_error);
}
