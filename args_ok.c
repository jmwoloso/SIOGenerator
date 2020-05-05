#include <stdio.h>
#include <string.h>
#include "constsw.h"
int args_ok(argc,argv,arg_opts,max_args,msg,fname)
int      argc;                
char     *argv[];             
unsigned char arg_opts[];     
int           max_args;       
unsigned char msg[];          
unsigned char fname[][BUFSIZ];
{                             
  int idx;                    
  int no_error = 1;           
  if (argc > max_args)        
  {
    printf(msg);
    no_error = 0;
  }
  else
  { 
    for (idx = 1; idx < argc && no_error; idx++)
      no_error = no_error && (argv[idx][1] == arg_opts[0] ||
			      argv[idx][1] == arg_opts[1] ||
			      argv[idx][1] == arg_opts[2]);
    if (no_error)
      for (idx = 1; idx < argc; idx++)
      {           
	switch (argv[idx][1])
	{
	  case 'f' : strcpy(fname[0],&argv[idx][2]);
		     break;
	  case 'd' : strcpy(fname[1],&argv[idx][2]);
		     break;
	  case 'c' : strcpy(fname[2],&argv[idx][2]);
		     break;
	}
      }
    else
      printf(msg);   
  }
  return(no_error);
}
