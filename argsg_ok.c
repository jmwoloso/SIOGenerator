#include <stdio.h>
#include <string.h>
#include "constsw.h"
int argsg_ok(argc,argv,max_args,msg1,msg2,msg3,msg4,msg5,fname)
int  argc;                             
char *argv[];                          
int  max_args;                         
unsigned char msg1[],msg2[],msg3[],    
	      msg4[],msg5[];
unsigned char fname[][BUFSIZ];         
{                                      
  int no_error = 1;                    
  if (argc > max_args )                
  {
    printf("%s%s%s%s%s",msg1,msg2,msg3,msg4,msg5);
    no_error = 0;
  }
  else if (argc > 1)
  {
    strcpy(fname[1],argv[1]);          
    if (argc > 2)
      strcpy(fname[2],argv[2]);        
  }
  return(no_error);
}
