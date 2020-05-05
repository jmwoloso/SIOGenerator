#include <stdio.h>
#include <string.h>
#include "constsw.h"
#include "structsw.h"
#include "protosw.h"
void mk_float(db_spec,decoded,fld_idx,tmp_buf)
FIL_SPC       *db_spec;                
unsigned char decoded[];               
int           fld_idx;                 
unsigned char *tmp_buf;                
{
  unsigned char fmt[20];               
  unsigned char *ptr;                  
  long double   rannumd;               
  if (DB_SPC.rpt_idx == DB_SPC.rpt_lmt)
  {
    if (DB_SPC.order[0] == SEQ_ORD)
    {
      if ((DB_SPC.seed.d >= DB_SPC.upper.d && DB_SPC.intrv.d > 0) ||
	    (DB_SPC.seed.d <= DB_SPC.upper.d && DB_SPC.intrv.d < 0))
	  DB_SPC.seed.d = DB_SPC.lower.d - DB_SPC.intrv.d;
	rannumd = DB_SPC.seed.d += DB_SPC.intrv.d;
    }
    else
    {
      rannumd = DB_SPC.intrv.d * randflt(&DB_SPC.seed.l[2]);
      rannumd += DB_SPC.lower.d;
    }
    sprintf(fmt,"%s","%.");
    if (DB_SPC.option == OFLTPF)       
    {
      sprintf(fmt+strlen(fmt),"%dLf",DB_SPC.num_dec);
      sprintf(decoded,fmt,rannumd);
    }
    else
    {
      sprintf(fmt+strlen(fmt),"%dLE",DB_SPC.num_dec+1);
      sprintf(decoded,fmt,rannumd);
      if (DB_SPC.option == OFLTPD)
      {
	ptr = strchr(decoded,'E');
	*ptr = 'D';
      }
    }
    if (DB_SPC.num_dec == 0 && (ptr = strchr(decoded,'.')))
      while (*ptr)
      {
	*ptr = *(ptr + 2);
	++ptr;
      }
    jst_nmrc(decoded,DB_SPC.lnth,strlen(decoded),DB_SPC.type,
	     db_spec->rec_typ,tmp_buf);
    DB_SPC.rpt_idx = 1;                
    if (DB_SPC.sav_val != NULL)        
      strcpy(DB_SPC.sav_val,tmp_buf);  
  }
  else
  {
    ++DB_SPC.rpt_idx;                  
    strcpy(tmp_buf,DB_SPC.sav_val);    
  }                                    
}
