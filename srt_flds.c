#include <stdio.h>
#include "constsw.h"
#include "structsw.h"
#include "protosw.h"
int srt_flds(db_spec,decoded,num_flds)
FIL_SPC *db_spec;                
unsigned char **decoded;         
int     *num_flds;               
{
  int           jdx;             
  unsigned char *ptr;            
  FLD_DEF       temp;            
  jdx = *num_flds;
  if (*num_flds && db_spec->fld_spc[*num_flds].idx <
		   db_spec->fld_spc[*num_flds-1].idx)
  {                              
    temp = db_spec->fld_spc[*num_flds];
    ptr  = decoded[*num_flds];         
    db_spec->fld_spc[jdx] = db_spec->fld_spc[jdx-1];
    decoded[jdx] = decoded[jdx-1];
    --jdx;
    while (jdx > 0 && temp.idx < db_spec->fld_spc[jdx-1].idx)
    {                                  
      db_spec->fld_spc[jdx] = db_spec->fld_spc[jdx-1];
      decoded[jdx] = decoded[jdx-1];
      --jdx;
    }
    db_spec->fld_spc[jdx] = temp;      
    decoded[jdx] = ptr;                
  }
  ++*num_flds;                         
  return(set_buf(db_spec,jdx,decoded));
}
