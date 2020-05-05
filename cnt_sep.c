#include <stdio.h>
#include <string.h>
#include "constsw.h"
#include "structsw.h"
int cnt_sep(inp_text,ptr)              
unsigned char inp_text[];              
unsigned char **ptr;                   
{
  int  num_sep = 0;                    
  unsigned char *pt1;                  
  unsigned char *pt2;                  
  *ptr = inp_text;
  if (pt1 = strchr(*ptr,LIN_SEP))
    *pt1 = '\0';                       
  while ((pt1 = strchr(*ptr,CMA_SEP)) != NULL)
  {                                    
    ++num_sep;
    *pt1 = ' ';                        
    *ptr = ++pt1;                      
    if (num_sep == NUM_SEP)
      pt2 = *ptr;                      
  }
  *ptr = pt2;                          
  return(num_sep);
}
