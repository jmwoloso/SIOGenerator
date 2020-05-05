#include <string.h>
#include "constsw.h"
void skp_fld(inp_txt,pt1)              
unsigned char inp_txt[];               
unsigned char **pt1;                   
{
  int           idx;                   
  unsigned char *ptr;                  
  ptr = strchr(inp_txt,CMA_SEP) + 1;  
  *pt1 = ptr;
  for (idx = 0; idx < 2; idx++)
    *pt1 = strchr(*pt1,CMA_SEP) + 1;   
  strcpy(ptr,*pt1);                    
  *pt1 = ptr;
  for (idx = 0; idx < 3; idx++)        
    *pt1 = strchr(*pt1,CMA_SEP) + 1;
}
