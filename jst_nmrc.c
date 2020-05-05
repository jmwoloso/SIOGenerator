#include <stdio.h>
#include <string.h>
#include "constsw.h"
#include "structsw.h"
#include "protosw.h"
void jst_nmrc(decoded,flnth,slnth,type,rec_typ,tmp_buf)
unsigned char decoded[];               
int           flnth;                   
int           slnth;                   
unsigned char type[];                  
unsigned char rec_typ;                 
unsigned char tmp_buf[];               
{
  int           idx;                   
  if (rec_typ == VAR_LEN || slnth > flnth)
  {
    strcpy(tmp_buf,decoded);
    tmp_buf[flnth] = NUL_SEP;          
  }
  else
  {
    for (idx = 0; idx < flnth - slnth; idx++)
      if (!fld_typ(DEC_OPT,type) && strcmp(type,XYZAD) &&
	  !fld_typ(SPC_OPT,type) && !fld_typ(FLT_OPT,type))
	tmp_buf[idx] = BLNK1;          
      else
	tmp_buf[idx] = ZERO;           
    if (decoded[idx-flnth+slnth] == DSH_SEP)
    {                                  
      tmp_buf[0] = DSH_SEP;            
      if (idx > 0)                     
	tmp_buf[idx++] = ZERO;         
    }
    for ( ; idx < flnth; idx++)        
      tmp_buf[idx] = decoded[idx - flnth + slnth];
    tmp_buf[idx] = NUL_SEP;            
  }
  decoded[0] = NUL_SEP;                
}
