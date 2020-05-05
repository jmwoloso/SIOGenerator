#include <stdio.h>
#include <string.h>
#include "constsw.h"
#include "structsw.h"
int  set_unif(fld_idx,db_spec,uni_flds)
int           fld_idx;                 
FIL_SPC       *db_spec;                
int           *uni_flds;               
{
  int           ch = NUL_SEP;          
  unsigned char fname[BUFSIZ];         
  long          idx;                   
  int           no_error = 1;          
  sprintf(fname,"%s%03d",UNI_FIL,*uni_flds);
  ++*uni_flds;
  if (!(no_error = ((DB_SPC.fpuni = fopen(fname,"w+b")) != NULL)))
    printf("\nUnable to open file %s in set_unif()",fname);
  else
  {
    for (idx = 0; idx < (DB_SPC.upper.l[0] - DB_SPC.lower.l[0] + 1); idx++)
      fputc(ch,DB_SPC.fpuni);
  }
  return(no_error);
}
