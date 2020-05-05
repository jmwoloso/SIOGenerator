#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int filsopen(fname,fp,mode)    
unsigned char *fname;          
FILE **fp;                     
unsigned char *mode;           
{                              
  int  no_error = 1;           
  if ((*fp = fopen(fname,mode)) == NULL)
  {
  printf("\n Unable to open %s \n",fname);
    no_error = 0;
  }
  return(no_error);
}
