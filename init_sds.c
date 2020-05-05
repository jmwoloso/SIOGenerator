#include <stdio.h>
#include <string.h>
#include "constsw.h"
#include "structsw.h"
#include "protosw.h"
void init_sds(lower,intrv,order,type,fld_idx,decoded,seed)
long          lower;                   
long          intrv;                   
unsigned char order;                   
unsigned char type[];                  
int           fld_idx;                 
unsigned char **decoded;               
long          *seed;                   
{
  if (strcmp(type,XYZIN) &&            
      strcmp(type,XYZYF) &&            
      strcmp(type,XYZBO))              
  {
    decoded[fld_idx][0] = '\0';        
    if ((fld_typ(CST_OPT,type) || fld_typ(DEC_OPT,type) ||
	 fld_typ(DAT_OPT,type) || fld_typ(TIM_OPT,type) ||
     fld_typ(SPC_OPT,type) || !strcmp(type,XYZAD)) && order == SEQ_ORD)
      *seed = lower - intrv;           
    else if (fld_typ(CST_OPT,type))
      *seed = 0L;                      
  }
}
