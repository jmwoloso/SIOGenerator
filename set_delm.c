#include <ctype.h>
#include "constsw.h"
unsigned char set_delm(inp_text)
unsigned char inp_text[];
{
  int idx = -1;
  unsigned char ret_flag = BAD_SEP;
  while (isspace(inp_text[++idx]));    
  switch (toupper(inp_text[idx]))
  {
    case NUL_COD : ret_flag = NUL_SEP; 
		   break;
    case APS_COD : ret_flag = APS_SEP; 
		   break;
    case CMA_COD : ret_flag = CMA_SEP; 
		   break;
    case PIP_COD : ret_flag = PIP_SEP; 
		   break;
    case SLH_COD : ret_flag = SLH_SEP; 
		   break;
    case TAB_COD : ret_flag = TAB_SEP; 
		   break;
    case LIN_COD : ret_flag = LIN_SEP; 
		   break;
  }
  return(ret_flag);
}
