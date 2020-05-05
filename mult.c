#include "constsw.h"
long mult(p,q)                         
long p;                                
long q;                                
{                                      
  long p1,p0,q1,q0;                    
  p1 = p / MAX_DIV;
  p0 = p % MAX_DIV;
  q1 = q / MAX_DIV;
  q0 = q % MAX_DIV;
  return((((p0 * q1 + p1 * q0) % MAX_DIV) * MAX_DIV + p0 * q0) % MAX_RND);
}
