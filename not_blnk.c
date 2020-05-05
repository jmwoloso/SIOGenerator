#include <ctype.h>
#include <string.h>
unsigned char not_blnk(inp_text)       
unsigned char inp_text[];              
{                                      
  unsigned char *ptr = inp_text - 1;   
  while (isspace(*++ptr));             
  if (*ptr == '*' || (*ptr == '/' && *(ptr+1) == '*'))
    *ptr = '\0';                       
  else
  {
    --ptr;
    while (!isalnum(*++ptr) && *ptr);  
  }
  return(*ptr);
}
