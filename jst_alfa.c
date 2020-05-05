#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "constsw.h"
#include "structsw.h"
void jst_alfa(decoded,flnth,slnth,rec_typ,tmp_buf)
unsigned char decoded[];               
int           flnth;                   
int           slnth;                   
unsigned char rec_typ;                 
unsigned char *tmp_buf;                
{
  int           idx;                   
  unsigned char *ptr;                  
  strcpy(tmp_buf,decoded);             
  decoded[0] = NUL_SEP;                
  if (rec_typ == VAR_LEN)
  {                                    
    ptr = tmp_buf + flnth;
    while (isspace(*--ptr));
    *++ptr = NUL_SEP;
  }
  else if (slnth > flnth)
    tmp_buf[flnth] = NUL_SEP;          
  else
  {                                    
    for (idx = slnth; idx < flnth; idx++)
      tmp_buf[idx] = BLNK1;
    tmp_buf[idx] = NUL_SEP;
  }
}
