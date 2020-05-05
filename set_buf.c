#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "constsw.h"
#include "structsw.h"
#include "protosw.h"
int set_buf(db_spec,idx,decoded)       
FIL_SPC       *db_spec;                
int           idx;                     
unsigned char **decoded;               
{
  int no_error = 1;                    
  int           fld_lens[] =           
        { XYZEF_LN,XYZDR_LN,XYZAC_LN,XYZEX_LN,XYZUS_LN,
          XYZTA_LN,XYZ05_LN,XYZ09_LN,XYZ9D_LN,XYZEL_LN,
          XYZMI_LN,XYZR1_LN,INTER_LN,FLTPF_LN,FLTPE_LN,
          FLTPD_LN,XYZAD_LN,XYZKD_LN,XYZED_LN,XYZEM_LN,
          XYZFX_LN,XYZNO_LN,XYZPA_LN,XYZNE_LN,XYZLL_LN,
          XYZBR_LN,XYZDY_LN,XYZM1_LN,XYZD2_LN,XYZM2_LN,
          XYZM3_LN,XYZY1_LN,XYZHR_LN,XYZAP_LN,XYZCO_LN,
          XYZPR_LN,XYZNK_LN,XYZIN_LN,RANDC_LN,RANDA_LN,
          XYZD3_LN,XYZM4_LN,XYZD4_LN,XYZM5_LN,XYZY3_LN,
          XYZM6_LN,XYZ4D_LN,XYZY4_LN,XYZ2D_LN,XYZY2_LN,
          XYZP1_LN,XYZP2_LN,XYZP3_LN,XYZIX_LN,XYZTN_LN,
          XYZTB_LN,XYZYF_LN,XYZBO_LN,XYZDF };
  int jdx = idx;                       
   if (strcmp(DB_TYPE,XYZTA) && strcmp(DB_TYPE,XYZIN) &&
       strcmp(DB_TYPE,XYZDR) && strcmp(DB_TYPE,XYZFX) &&
      !fld_typ(ZIP_OPT,DB_TYPE) && !fld_typ(PHN_OPT,DB_TYPE))
   {
       if(strcmp(db_spec->fld_spc[idx].type,XYZYF))
   no_error = (decoded[idx] =       
	   (unsigned char *)calloc(fld_lens[db_spec->fld_spc[idx].option],
	    sizeof(unsigned char))) != NULL;
   }
  else if (!strcmp(db_spec->fld_spc[idx].type,XYZTA))
  {                                    
    while (--jdx >= 0 && !fld_typ(CTY_STA,DB_TYPE));
    if (jdx < 0 || !strcmp(DB_TYPE,XYZTA))
    no_error = (decoded[idx] =       
		 (unsigned char *)calloc(fld_lens[db_spec->fld_spc[idx].option],
		 sizeof(unsigned char))) != NULL;
	else
	     decoded[idx] = decoded[jdx];     
	}
  else if (fld_typ(ZIP_OPT,db_spec->fld_spc[idx].type))
  {                                    
    while (--jdx >= 0 && !fld_typ(CTY_STA,DB_TYPE) &&
			 !fld_typ(ZIP_OPT,DB_TYPE));
    if (jdx < 0 || fld_typ(ZIP_OPT,DB_TYPE))
	no_error = (decoded[idx] =       
		 (unsigned char *)calloc(fld_lens[db_spec->fld_spc[idx].option],
		 sizeof(unsigned char))) != NULL;
	else
	     decoded[idx] = decoded[jdx];     
	}
else if (!strcmp(db_spec->fld_spc[idx].type,XYZAC))
{                                    
    while (--jdx >= 0 && !fld_typ(CTY_STA,DB_TYPE) &&
			 !fld_typ(ZIP_OPT,DB_TYPE) &&
			 !fld_typ(PHN_OPT,DB_TYPE));
    if (jdx < 0 || fld_typ(PHN_OPT,DB_TYPE))
	no_error = (decoded[idx] =       
		(unsigned char *)calloc(fld_lens[db_spec->fld_spc[idx].option],
		 sizeof(unsigned char))) != NULL;
    else
	  decoded[idx] = decoded[jdx];     
	}
 else if (!strcmp(db_spec->fld_spc[idx].type,XYZNE))
{                                    
    while (--jdx >= 0 && !fld_typ(CTY_STA,DB_TYPE) &&
			 !fld_typ(ZIP_OPT,DB_TYPE) &&
			 !fld_typ(PHN_OPT,DB_TYPE));
    if (jdx < 0 || fld_typ(PHN_OPT,DB_TYPE))
	  no_error = (decoded[idx] =       
		 (unsigned char *)calloc(fld_lens[db_spec->fld_spc[idx].option],
		 sizeof(unsigned char))) != NULL;
	else
	  decoded[idx] = decoded[jdx];     
	}
else if (!strcmp(db_spec->fld_spc[idx].type,XYZEX))
{                                    
    while (--jdx >= 0 && strcmp(DB_TYPE,XYZ05) && strcmp(DB_TYPE,XYZ09)
		      && !fld_typ(CTY_STA,DB_TYPE)
		      && !fld_typ(ZIP_OPT,DB_TYPE)
		      && !fld_typ(PHN_OPT,DB_TYPE));
    if (jdx < 0 || !strcmp(DB_TYPE,XYZEX) || !strcmp(DB_TYPE,XYZNE) ||
           !strcmp(DB_TYPE,XYZNO))
	  no_error = (decoded[idx] =       
		 (unsigned char *)calloc(fld_lens[db_spec->fld_spc[idx].option],
		 sizeof(unsigned char))) != NULL;
	else
	  decoded[idx] = decoded[jdx];     
	}									   
else if (!strcmp(db_spec->fld_spc[idx].type,XYZNO))
{                                    
    while (--jdx >= 0 && strcmp(DB_TYPE,XYZ05) && strcmp(DB_TYPE,XYZ09)
		      && !fld_typ(CTY_STA,DB_TYPE) && !fld_typ(ZIP_OPT,DB_TYPE)
		      && !fld_typ(PHN_OPT,DB_TYPE));
    if (jdx < 0 || !strcmp(DB_TYPE,XYZEX) || !strcmp(DB_TYPE,XYZNE) ||
           !strcmp(DB_TYPE,XYZNO))
	  no_error = (decoded[idx] =       
		 (unsigned char *)calloc(fld_lens[db_spec->fld_spc[idx].option],
		 sizeof(unsigned char))) != NULL;
	else
	  decoded[idx] = decoded[jdx];     
	}                                    
else if (!strcmp(db_spec->fld_spc[idx].type,XYZDR))
  {                                    
    while (--jdx >= 0 && strcmp(DB_TYPE,XYZEF) && strcmp(DB_TYPE,XYZDR));
    if (jdx < 0 || !strcmp(DB_TYPE,XYZDR))
	  no_error = (decoded[idx] =       
		 (unsigned char *)calloc(fld_lens[db_spec->fld_spc[idx].option],
		 sizeof(unsigned char))) != NULL;
	else
	  decoded[idx] = decoded[jdx];     
	}
  else if (!strcmp(db_spec->fld_spc[idx].type,XYZFX))
  {                                    
    while (--jdx >= 0 && strcmp(DB_TYPE,XYZEF)
                      && strcmp(DB_TYPE,XYZDR)
                      && strcmp(DB_TYPE,XYZFX));
    if (jdx < 0 || !strcmp(DB_TYPE,XYZFX))
	  no_error = (decoded[idx] =       
		 (unsigned char *)calloc(fld_lens[db_spec->fld_spc[idx].option],
		 sizeof(unsigned char))) != NULL;
	else
	  decoded[idx] = decoded[jdx];     
}
  if (!no_error)
  printf("\nUnable to allocate memory in set_buf");
return(no_error);
}
