#include <stdio.h>
#include <float.h>
#include "constsw.h"
#include "structsw.h"
void set_bnds(option,lower,upper,intrv)
int  option;                           
long *lower;                           
long *upper;                           
long *intrv;                           
{
  switch(option)
  {
    case ORANDA : *upper = MAX_ALF;
    case ORANDC : *upper += (2 * MAX_ALF);
		  *lower = 1;
		  break;
    default     : *upper = MAX_RND;
  }
  if (*intrv == 0L)
    *intrv = 1L;
}
