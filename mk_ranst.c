#include <stdio.h>
#include <string.h>
#include "constsw.h"
#include "structsw.h"
#include "protosw.h"
void mk_ranst(fld_idx,db_spec,decoded,tmp_buf)
int           fld_idx;                 
FIL_SPC       *db_spec;                
unsigned char decoded[];               
unsigned char *tmp_buf;                
{
  int           factor;                
  int           idx,jdx;               
  int           lst_ch1,lst_ch2;       
  int           ul_cmb,ud_cmb,ld_cmb;  
  int           no_upc = 1, no_loc = 1,
		no_dgt = 1;            
  unsigned char str_buf[MAX_ALF*3];    
  if (DB_SPC.rpt_idx == DB_SPC.rpt_lmt)
  {
    set_tab(str_buf);                  
    if (!strcmp(DB_SPC.type,RANDC))    
    {                                  
      ul_cmb = DB_SPC.lnth > 1 && DB_SPC.lower.l[0] <= MAX_ALF &&
				  DB_SPC.upper.l[0] > MAX_ALF;
      for (idx = 0; idx < DB_SPC.lnth; idx++)
      {
	jdx = randmar(DB_SPC.upper.l[0]-DB_SPC.lower.l[0]+1,&DB_SPC.seed.l[0])
	      + DB_SPC.lower.l[0] - 1; 
	if (ul_cmb)                    
	  if (jdx >= MAX_ALF)
	    no_loc = 0;                
	  else
	    no_upc = 0;                
	decoded[idx] = str_buf[jdx];   
      }
      decoded[idx] = '\0';             
      if (ul_cmb && (no_upc || no_loc))
      {                                
	idx = randmar((long)DB_SPC.lnth,&DB_SPC.seed.l[0]);
	if (no_upc)                    
	  jdx = randmar(MAX_ALF-DB_SPC.lower.l[0],&DB_SPC.seed.l[0]) +
		  DB_SPC.lower.l[0] - 1;
	else                           
	  jdx = randmar(DB_SPC.upper.l[0]-MAX_ALF-1,&DB_SPC.seed.l[0]) +
		  MAX_ALF;
	decoded[idx] = str_buf[jdx];   
      }
    }
    else
    {                                  
      ld_cmb = DB_SPC.lnth > 1 && DB_SPC.lower.l[0] > MAX_ALF &&
	       DB_SPC.upper.l[0] <= 3 * MAX_ALF;
      ud_cmb = DB_SPC.lnth > 1 && DB_SPC.upper.l[0] <=  MAX_ALF;
      ul_cmb = DB_SPC.lnth > 2 && DB_SPC.lower.l[0] <= MAX_ALF &&
				  DB_SPC.upper.l[0] >  MAX_ALF;
      factor = DB_SPC.upper.l[0] > (2 * MAX_ALF) ? 0 : MAX_ALF;
      for (idx = 0; idx < DB_SPC.lnth; idx++)
      {
	jdx = randmar(DB_SPC.upper.l[0]-DB_SPC.lower.l[0]+1+factor,
		      &DB_SPC.seed.l[0]) + DB_SPC.lower.l[0] - 1;
	if (ul_cmb)                    
	  if (jdx < MAX_ALF)
	    no_upc = 0;                
	  else if (jdx >= DB_SPC.upper.l[0])
	    no_dgt = 0;                
	  else
	    no_loc = 0;                
	else if (ld_cmb)               
	  if (jdx < 2 * MAX_ALF)
	    no_loc = 0;                
	  else
	    no_dgt = 0;                
	else
	  if (jdx < DB_SPC.upper.l[0])
	    no_upc = 0;                
	  else
	    no_dgt = 0;                
	if (jdx < DB_SPC.upper.l[0])
	  decoded[idx] = str_buf[jdx]; 
	else                           
	  decoded[idx] = str_buf[(int)(jdx - DB_SPC.upper.l[0] + 2 * MAX_ALF)];
      }
      decoded[idx] = '\0';             
      if ((ud_cmb && (no_upc || no_dgt)) ||
	  (ld_cmb && (no_loc || no_dgt)) ||
	  (ul_cmb && (no_loc || no_upc || no_dgt)))
      {                                
	idx = randmar((long)DB_SPC.lnth,&DB_SPC.seed.l[0]);
	if (ud_cmb)                    
	{
	  if (no_upc)                  
	    jdx = randmar(DB_SPC.upper.l[0]-DB_SPC.lower.l[0]+1,
			  &DB_SPC.seed.l[0]) + DB_SPC.lower.l[0] - 1;
	  else                         
	    jdx = randmar(MAX_ALF,&DB_SPC.seed.l[0]) + 2 * MAX_ALF;
	  decoded[idx] = str_buf[jdx]; 
	}
	else if (ld_cmb)
	{                              
	  if (no_loc)                  
	    jdx = randmar(2*MAX_ALF-DB_SPC.lower.l[0]+1,&DB_SPC.seed.l[0]) +
		    DB_SPC.lower.l[0] - 1;
	  else                         
	    jdx = randmar(DB_SPC.upper.l[0]-2*MAX_ALF,&DB_SPC.seed.l[0]) +
		   2 * MAX_ALF;
	  decoded[idx] = str_buf[jdx]; 
	}
	else
	{                              
	  if (no_dgt)
	  {                            
	    if (DB_SPC.upper.l[0] <= 2 * MAX_ALF)
	      jdx = randmar(MAX_ALF-1,&DB_SPC.seed.l[0]) + 2 * MAX_ALF;
	    else
	      jdx = randmar(DB_SPC.upper.l[0]-2*MAX_ALF,&DB_SPC.seed.l[0]) +
		      2 * MAX_ALF;
	    if (no_loc)
	    {                          
	      decoded[idx] = str_buf[jdx];
	      if (DB_SPC.upper.l[0] > 2 * MAX_ALF)
		jdx = randmar(MAX_ALF-1,&DB_SPC.seed.l[0]) + MAX_ALF;
	      else
		jdx = randmar(DB_SPC.upper.l[0]-MAX_ALF-1,&DB_SPC.seed.l[0])
			+ MAX_ALF;
	      if (idx > 0)             
		decoded[--idx] = str_buf[jdx];
	      else                     
		decoded[++idx] = str_buf[jdx];
	    }
	    else if (no_upc)
	    {                          
	      decoded[idx] = str_buf[jdx];
	      jdx = randmar(MAX_ALF-DB_SPC.lower.l[0]+1,&DB_SPC.seed.l[0]) +
		      DB_SPC.lower.l[0] - 1;
	      if (idx > 0)             
		decoded[--idx] = str_buf[jdx];
	      else                     
		decoded[++idx] = str_buf[jdx];
	    }
	    else if (cnt_chr(decoded,DB_SPC.lnth,'u',&lst_ch1) >
		     cnt_chr(decoded,DB_SPC.lnth,'l',&lst_ch2))
	      decoded[lst_ch1] = str_buf[jdx];
	    else                       
	      decoded[lst_ch2] = str_buf[jdx];
	  }
	  else if (no_loc)
	  {                            
	    if (DB_SPC.upper.l[0] > 2 * MAX_ALF)
	      jdx = randmar(MAX_ALF-1,&DB_SPC.seed.l[0]) + MAX_ALF;
	    else
	      jdx = randmar(DB_SPC.upper.l[0]-MAX_ALF-1,&DB_SPC.seed.l[0])
		      + MAX_ALF;
	    if (no_upc)
	    {                          
	      decoded[idx] = str_buf[jdx];
	      jdx = randmar(MAX_ALF-DB_SPC.lower.l[0]+1,&DB_SPC.seed.l[0]) +
		      DB_SPC.lower.l[0] - 1;
	      if (idx > 0)             
		decoded[--idx] = str_buf[jdx];
	      else                     
		decoded[++idx] = str_buf[jdx];
	    }
	    else if (cnt_chr(decoded,DB_SPC.lnth,'u',&lst_ch1) >
		     cnt_chr(decoded,DB_SPC.lnth,'d',&lst_ch2))
	      decoded[lst_ch1] = str_buf[jdx];
	    else                       
	      decoded[lst_ch2] = str_buf[jdx];
	  }
	  else
	  {                            
	    jdx = randmar(MAX_ALF-DB_SPC.lower.l[0]+1,&DB_SPC.seed.l[0]) +
		    DB_SPC.lower.l[0] - 1;
	    if (cnt_chr(decoded,DB_SPC.lnth,'l',&lst_ch1) >
		   cnt_chr(decoded,DB_SPC.lnth,'d',&lst_ch2))
	      decoded[lst_ch1] = str_buf[jdx];
	    else                       
	      decoded[lst_ch2] = str_buf[jdx];
	  }
	}
      }
    }
    jst_alfa(decoded,DB_SPC.lnth,DB_SPC.lnth,db_spec->rec_typ,tmp_buf);
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
