#include <stdio.h>
#include "constsw.h"
#include "structsw.h"
int in_seq(db_spec,num_flds)           
FIL_SPC *db_spec;                      
int     num_flds;                      
{                                      
  int idx;                             
  for (idx = 0; idx < num_flds; idx++)
    if (db_spec->fld_spc[idx].idx != idx)
      break;
  return(idx == num_flds);
}
