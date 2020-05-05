#include <stdio.h>
#include <string.h>
#include "constsw.h"
#include "structsw.h"
#include "protosw.h"
void mk_inter(db_spec,decoded,fld_idx,tmp_buf)
FIL_SPC       *db_spec;                
unsigned char decoded[];               
int           fld_idx;                 
unsigned char *tmp_buf;                
{
  int  uni_val;                        
  long idx;                            
  long rannum;                         
  char neg_msk = 0x0f;                 
  char neg_chr = 0xb0;                 
  int  sgn_flg;                        
  if (DB_SPC.rpt_idx == DB_SPC.rpt_lmt)
  {
    if (!fld_typ(SPC_OPT,DB_SPC.type))
      if (DB_SPC.order[0] == SEQ_ORD)
      {
	if ((DB_SPC.seed.l[0] >= DB_SPC.upper.l[0] &&
	     DB_SPC.intrv.l[0] > 0)                ||
	    (DB_SPC.seed.l[0] <= DB_SPC.upper.l[0] &&
	     DB_SPC.intrv.l[0] < 0))
	  DB_SPC.seed.l[0] = DB_SPC.lower.l[0] - DB_SPC.intrv.l[0];
	rannum = DB_SPC.seed.l[0] += DB_SPC.intrv.l[0];
      }
      else                             
      {
	rannum = randmar(DB_SPC.upper.l[0] - DB_SPC.lower.l[0] + 1,
			 &DB_SPC.seed.l[0]);
	if (DB_SPC.order[0] == UNI_ORD)
	{                              
	  fseek(DB_SPC.fpuni,rannum,SEEK_SET);
	  if (uni_val = fgetc(DB_SPC.fpuni))
	  {                            
	    rannum = 0;                
	    fseek(DB_SPC.fpuni,rannum,SEEK_SET);
	    while (rannum < DB_SPC.upper.l[0] - DB_SPC.lower.l[0] &&
		   (uni_val = fgetc(DB_SPC.fpuni)))
	      ++rannum;
	    if (rannum >= DB_SPC.upper.l[0] - DB_SPC.lower.l[0])
	    {                          
	      printf("\nUnique value not found in Make Integer Routine()\n");
	      rannum = 0;
	    }
	  }                            
	  fseek(DB_SPC.fpuni,rannum,SEEK_SET);
	  fputc(UNI_ORD,DB_SPC.fpuni);
	}
	rannum += DB_SPC.lower.l[0];   
      }
    else
      if (DB_SPC.order[0] == SEQ_ORD)
      {
	if ((DB_SPC.seed.l[2] >= DB_SPC.upper.l[2] && DB_SPC.intrv.l[2] > 0) ||
	    (DB_SPC.seed.l[2] <= DB_SPC.upper.l[2] && DB_SPC.intrv.l[2] < 0))
	{                              
	  DB_SPC.seed.l[2] = DB_SPC.lower.l[2] - DB_SPC.intrv.l[2];
	  if (DB_SPC.intrv.l[1] == 0)
	    DB_SPC.seed.l[1] += 1;
	  else
	    DB_SPC.seed.l[1] += DB_SPC.intrv.l[1];
	}
	rannum = DB_SPC.seed.l[2] += DB_SPC.intrv.l[2];
      }
      else                             
      {
	rannum = randmar(DB_SPC.upper.l[2] - DB_SPC.lower.l[2] + 1,
			 &DB_SPC.seed.l[2]);
	rannum += DB_SPC.lower.l[2];   
      }
    if (DB_SPC.option == OXYZP1 || DB_SPC.option == OXYZP3 ||
    DB_SPC.option == OXYZP2)
      sprintf(decoded,"%04ld",rannum);
    else if (DB_SPC.option == OINTER)
      if (DB_SPC.num_dec == 0)
	sprintf(decoded,"%ld",rannum); 
      else                             
	sprintf(decoded,"%.*lf",DB_SPC.num_dec,
				rannum/pow_10(DB_SPC.num_dec));
    else if (DB_SPC.option == OXYZAD)  
      sprintf(decoded,"%x",rannum);
    else
    {
      if (sgn_flg = (rannum < 0))      
	rannum *= -1;                  
      sprintf(decoded,"%ld",rannum);
      if (DB_SPC.option == OXYZED)
      {
	if (sgn_flg)                   
	  decoded[strlen(decoded)-1] =
	    decoded[strlen(decoded)-1] & neg_msk | neg_chr;
      }
      else
      {
	if ((strlen(decoded) % 2) == 0)
	{                              
	  for (idx = strlen(decoded) + 1; idx > 0; idx--)
	    decoded[idx] = decoded[idx-1];
	  decoded[0] = ZERO;
	}
	for (idx = 0; idx < strlen(decoded); idx += 2)
	{                              
	  decoded[idx/2] = (decoded[idx] & neg_msk) << 4;
	  decoded[idx/2] = decoded[idx/2] | (decoded[idx+1] & neg_msk);
	}                              
	decoded[idx/2-1] |= sgn_flg ? (neg_chr >> 4) & neg_msk : neg_msk;
	decoded[idx/2] = '\0';
      }
    }
    jst_nmrc(decoded,DB_SPC.lnth,strlen(decoded),DB_SPC.type,
	     db_spec->rec_typ,tmp_buf);
    if (!fld_typ(SPC_OPT,DB_SPC.type)) 
    {                                  
      DB_SPC.rpt_idx = 1;              
      if (DB_SPC.sav_val != NULL)      
	strcpy(DB_SPC.sav_val,tmp_buf);
    }
  }
  else
  {
    ++DB_SPC.rpt_idx;                  
    strcpy(tmp_buf,DB_SPC.sav_val);    
  }                                    
}
