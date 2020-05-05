#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "constsw.h"
#include "structsw.h"
#include "protosw.h"
int mk_blank(db_spec,fld_idx,decoded,tmp_buf)
FIL_SPC       *db_spec;                
int           fld_idx;                 
unsigned char decoded[];               
unsigned char *tmp_buf;                
{
  int no_error = 1;                    
  if (DB_SPC.rpt_idx == DB_SPC.rpt_lmt)
  {
    decoded[0] = BLNK1;                
    decoded[1] = '\0';
    jst_alfa(decoded,DB_SPC.lnth,strlen(decoded),db_spec->rec_typ,tmp_buf);
    DB_SPC.rpt_idx = 0;                
    if (DB_SPC.sav_val == NULL)
      if (!(no_error = ((DB_SPC.sav_val =
			(unsigned char *)malloc((strlen(tmp_buf) + 1)
			 * sizeof(unsigned char))) != NULL)))
	printf("\nUnable to allocate memory in mk_blank()");
    if (no_error)                      
      strcpy(DB_SPC.sav_val,tmp_buf);  
  }
  else                                 
    strcpy(tmp_buf,DB_SPC.sav_val);
  return(no_error);
}
