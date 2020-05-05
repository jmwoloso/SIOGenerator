#include <stdio.h>
#include <string.h>
#include "constsw.h"
#include "structsw.h"
int chk_ran(num_flds,db_spec,err_buf)
int           *num_flds;               
FIL_SPC       *db_spec;                
char          err_buf[];               
{
  int           no_error = 1;          
  int           factor;                
  factor = !strcmp(DB_SPEC.type,RANDC) ? 0 : MAX_ALF;
  if (no_error = ((DB_SPEC.lower.l[0] > 0) &&
		    (DB_SPEC.upper.l[0] <= (MAX_ALF * 2 + factor))))
    if (!strcmp(DB_SPEC.type,RANDC) && DB_SPEC.upper.l[0] > (MAX_ALF * 2))
      no_error = DB_SPEC.lower.l[0] <= (MAX_ALF * 2);
  if (!no_error)
    sprintf(err_buf,"%s","Illegal alphabetic range");
  return(no_error);
}
