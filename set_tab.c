#include <stdio.h>
#include <string.h>
#include "constsw.h"
#include "structsw.h"
void set_tab(str_buf)
unsigned char str_buf[];               
{
  int         idx,jdx;                 
  str_buf[0] = 'A';    
  for (idx = 1; idx < MAX_ALF; idx++)  
    str_buf[idx] = str_buf[idx-1] + 1;
  str_buf[idx++] = 'a';                
  for (; idx < MAX_ALF * 2; idx++)     
    str_buf[idx] = str_buf[idx-1] + 1;
  str_buf[idx++] = '0';
  str_buf[idx+9] = '0';
  str_buf[idx+19] = '0';
  for (; idx < MAX_ALF * 2 + 10; idx++)
  {                                    
    str_buf[idx] = str_buf[idx-1] + 1;
    str_buf[idx+10] = str_buf[idx];
    if (idx < MAX_ALF * 2 + 6)
      str_buf[idx+20] = str_buf[idx];
  }
}
