#include <string.h>
#include "constsw.h"
int fld_typ(option,type)               
int           option;                  
unsigned char type[];                  
{
  switch(option)
  {
    case CST_OPT :  return (!strcmp(type,XYZTB) || !strcmp(type,XYZTN) ||
                !strcmp(type,XYZDF));
		    break;
    case CTY_STA :  return (!strcmp(type,XYZUS) || !strcmp(type,XYZTA));
		    break;
    case DAT_OPT :  return (!strcmp(type,XYZM5) || !strcmp(type,XYZM1) ||
                !strcmp(type,XYZY3) || !strcmp(type,XYZM6) ||
                !strcmp(type,XYZDY) || !strcmp(type,XYZD2) ||
                !strcmp(type,XYZM2) || !strcmp(type,XYZM3) ||
                !strcmp(type,XYZY1) || !strcmp(type,XYZD3) ||
                !strcmp(type,XYZM4) || !strcmp(type,XYZM5) ||
                !strcmp(type,XYZ4D) || !strcmp(type,XYZY4) ||
                !strcmp(type,XYZ2D) || !strcmp(type,XYZY2) ||
                !strcmp(type,XYZLL) || !strcmp(type,XYZBR));
		    break;
    case DEC_OPT :  return (!strcmp(type,INTER) || !strcmp(type,XYZKD) ||
                !strcmp(type,XYZED));
		    break;
    case FLT_OPT :  return (!strcmp(type,FLTPF) || !strcmp(type,FLTPE) ||
			    !strcmp(type,FLTPD));
		    break;
    case JUL_OPT :  return (!strcmp(type,XYZY4) || !strcmp(type,XYZY2) ||
                !strcmp(type,XYZ4D) || !strcmp(type,XYZ2D));
		    break;
    case PHN_OPT :  return (!strcmp(type,XYZNE) || !strcmp(type,XYZEX) ||
                !strcmp(type,XYZNO) || !strcmp(type,XYZAC));
		    break;
    case RAN_OPT :  return (!strcmp(type,RANDA) || !strcmp(type,RANDC));
		    break;
    case SPC_OPT :  return (!strcmp(type,XYZP1) || !strcmp(type,XYZP2) ||
                !strcmp(type,XYZP3) || !strcmp(type,XYZIX));
		    break;
    case TIM_OPT :  return (!strcmp(type,XYZHR) || !strcmp(type,XYZAP) ||
                !strcmp(type,XYZCO) || !strcmp(type,XYZPR));
		    break;
    case YR_LAST :  return (!strcmp(type,XYZY3) || !strcmp(type,XYZDY) ||
                !strcmp(type,XYZD2) || !strcmp(type,XYZY1) ||
                !strcmp(type,XYZD3) || !strcmp(type,XYZD4) ||
                !strcmp(type,XYZY4) || !strcmp(type,XYZY2) ||
                !strcmp(type,XYZLL) || !strcmp(type,XYZBR));
		    break;
    case ZIP_OPT :  return (!strcmp(type,XYZ09) || !strcmp(type,XYZ05) ||
                !strcmp(type,XYZ9D));
		    break;
    case YR4_OPT :  return (!strcmp(type,XYZY3) || !strcmp(type,XYZM6) ||
                !strcmp(type,XYZD3) || !strcmp(type,XYZM4) ||
                !strcmp(type,XYZD4) || !strcmp(type,XYZM5) ||
                !strcmp(type,XYZ4D) || !strcmp(type,XYZY4) ||
                !strcmp(type,XYZLL) || !strcmp(type,XYZBR));
		    break;
  }
}
