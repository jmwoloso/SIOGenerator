#include <stdio.h>
#include "constsw.h"
#include "structsw.h"
void set_trlr(num_flds,db_spec,trailer)
int     num_flds;                    
FIL_SPC *db_spec;                    
TRL_REC trailer[MAX_FIL];            
{
  int           fld_idx;             
  int           idx;                 
  long          temp,temp1;          
  for (idx = 0; idx < MAX_FIL; idx++)
    if (db_spec->fpbin[idx] != NULL) 
    {
      fseek(db_spec->fpbin[idx],-(long)sizeof(TRL_REC),SEEK_END);
      fread(&trailer[idx],sizeof(TRL_REC),1,db_spec->fpbin[idx]);
      temp = 0;
      for (fld_idx = 0; fld_idx < num_flds; fld_idx++)
	if (DB_SPC.file_idx == idx)
	  if (temp == 0)             
	  {                          
	    if (DB_SPC.lower.l[0] >= TRLR_RC.num_recs)
	    {
	      DB_SPC.upper.l[0] -= DB_SPC.lower.l[0];
	      DB_SPC.lower.l[0] = 0;
	    }
	    if (DB_SPC.upper.l[0] - DB_SPC.lower.l[0] > TRLR_RC.num_recs)
	    {
	      DB_SPC.upper.l[0] = trailer[idx].num_recs;
	      DB_SPC.lower.l[0] = 0;
	    }
	    else if (DB_SPC.upper.l[0] > TRLR_RC.num_recs)
	    {
	      DB_SPC.upper.l[0] = TRLR_RC.num_recs;
	    }
	    if (DB_SPC.lower.l[0] > 0) 
	      --DB_SPC.lower.l[0];
	    temp1 = DB_SPC.lower.l[0];
	    temp = DB_SPC.upper.l[0];
	  }
	  else
	  {
	    DB_SPC.lower.l[0] = temp1;
	    DB_SPC.upper.l[0] = temp;
	  }
    }
}
