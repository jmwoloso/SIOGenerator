#include <stdio.h>
#include <string.h>
#include "constsw.h"
#include "structsw.h"
#include "protosw.h"
void init_cod(fptab,size,code_table,key_str)
FILE          **fptab;                 
int           size;                    
unsigned char code_table[][TAB_SIZ];   
unsigned char key_str[KEY_LEN];        
{
  int           idx;                   
  fread(code_table,size,1,*fptab);     
  closfils(fptab);
  strcpy(key_str,KEY_STR);             
  for (idx = 0; idx < (KEY_LEN / strlen(KEY_STR)) - 1; idx++)
    strcat(key_str,KEY_STR);
}
