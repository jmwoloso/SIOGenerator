#include <stdio.h>
#include "constsw.h"
#include "structsw.h"
#include "protosw.h"
long randmar(r,seed)                   
long r;                                
long *seed;                            
{                                      
  long ansl;                           
  *seed = (mult(*seed,MAX_MLT) + 1) % MAX_RND;
  ansl = (long)((((double)*seed / MAX_DIV) * r) / MAX_DIV);
  return(ansl);
}
