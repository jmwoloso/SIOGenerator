double pow_10(exp)                     
int exp;                               
{
  int  idx;                            
  double base = 1.0;                   
  for (idx = 0; idx < exp; idx++)
    base *= 10L;
  return(base);
}
