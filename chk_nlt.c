#include <stdio.h>
#include <string.h>
#include "constsw.h"
#include "structsw.h"
#include "protosw.h"
int chk_nlt(num_flds,db_spec,err_buf)
int           *num_flds;               
FIL_SPC       *db_spec;                
char          err_buf[];               
{
  unsigned char fld_types[NUM_TYP][FLD_LEN] ={ XYZEF,XYZDR,XYZAC,XYZEX,XYZUS,
                           XYZTA,XYZ05,XYZ09,XYZ9D,XYZEL,
                           XYZMI,XYZR1,INTER,FLTPF,FLTPE,
                           FLTPD,XYZAD,XYZKD,XYZED,XYZEM,
                           XYZFX,XYZNO,XYZPA,XYZNE,XYZLL,
                           XYZBR,XYZDY,XYZM1,XYZD2,XYZM2,
                           XYZM3,XYZY1,XYZHR,XYZAP,XYZCO,
                           XYZPR,XYZNK,XYZIN,RANDC,RANDA,
                           XYZD3,XYZM4,XYZD4,XYZM5,XYZY3,
                           XYZM6,XYZ4D,XYZY4,XYZ2D,XYZY2,
                           XYZP1,XYZP2,XYZP3,XYZIX,XYZTN,
                           XYZTB,XYZYF,XYZBO,XYZDF };
  int           fil_idx[NUM_TYP] ={ XXYZEF,XXYZDR,XXYZAC,XXYZEX,XXYZUS,
                           XXYZTA,XXYZ05,XXYZ09,XXYZ9D,XXYZEL,
                           XXYZMI,XXYZR1,INTER,FLTPF,FLTPE,
                           FLTPD,XXYZAD,XXYZKD,XXYZED,XXYZEM,
                           XXYZFX,XXYZNO,XXYZPA,XXYZNE,XXYZLL,
                           XXYZBR,XXYZDY,XXYZM1,XXYZD2,XXYZM2,
                           XXYZM3,XXYZY1,XXYZHR,XXYZAP,XXYZCO,
                           XXYZPR,XXYZNK,XXYZIN,RANDC,RANDA,
                           XXYZD3,XXYZM4,XXYZD4,XXYZM5,XXYZY3,
                           XXYZM6,XXYZ4D,XXYZY4,XXYZ2D,XXYZY2,
                           XXYZP1,XXYZP2,XXYZP3,XXYZIX,XXYZTN,
                           XXYZTB,XXYZYF,XXYZBO,XXYZDF };
  unsigned char file_name[FLD_LEN*2];  
  int           idx;                   
  int           no_error = 1;          
  if (!(no_error = (DB_SPEC.idx > 0 && DB_SPEC.idx <= MAX_TYP)))
    sprintf(err_buf,"%s","Illegal field number");
  else if (!(no_error = (DB_SPEC.lnth > 0 && DB_SPEC.lnth <= MAX_FLD)))
    sprintf(err_buf,"%s","Field length is illegal");
  else
  {                                    
    for (idx = 0; idx < NUM_TYP; idx++)
      if (!strcmp(fld_types[idx],DB_SPEC.type))
	break;
    if (!(no_error = (idx < NUM_TYP)))
      sprintf(err_buf,"%s","Illegal field fill type");
    else
    {                                  
      --DB_SPEC.idx;                   
      DB_SPEC.option = idx;
      DB_SPEC.file_idx = fil_idx[idx];
      if (fil_idx[idx] > NO_FILE && db_spec->fpbin[fil_idx[idx]] == NULL)
      {
          ;
      }
    }
  }
  return(no_error);
}
