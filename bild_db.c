#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <time.h>
#include <string.h>
#include "constsw.h"
#include "structsw.h"
void bild_db(tim_lmts,fpdb,db_spec,num_flds,code_table,key_str,decoded,
         fptrl,tim_zons)
TIM_REC       tim_lmts[];
FILE          **fpdb;
FIL_SPC       *db_spec;
int           num_flds;
unsigned char code_table[][TAB_SIZ];
unsigned char key_str[];
unsigned char **decoded;
FILE          **fptrl;
unsigned char tim_zons[][4];
{
  int           fld_idx;
  int           cst_idx;
  int           csz_off[] =
        { NPA_OFF,NXX_OFF,CTY_OFF,STA_OFF,ZIP_OFF };
  int           idx;
  int           nam_off[] =
        { NAM_OFF,SEX_OFF };
  int           no_error = 1;
  unsigned char prefix[3];
  long          rec_idx;
  unsigned char sex_flg;
  int           tim_idx;
  unsigned char tmp_buf[MAX_FLD];
  TRL_REC       trailer[MAX_FIL];
  time_t        mytime;
  double        interval;
  long          ctr;
  int			local_idx;
  int           file_length = 0;
  int           file_length_total = 0;
  time_t begin;
  time_t end;
  time(&begin);
  set_trlr(num_flds,db_spec,trailer);
  for (fld_idx = 0; fld_idx < num_flds; fld_idx++)
  {
    if (fld_typ(FLT_OPT,DB_SPC.type))
    {
      decoded[fld_idx][0] = '\0';
      if (DB_SPC.order[0] == SEQ_ORD)
    DB_SPC.seed.d = DB_SPC.lower.d - DB_SPC.intrv.d;
    }
    else
    {
      init_sds(DB_SPC.lower.l[0],DB_SPC.intrv.l[0],DB_SPC.order[0],
           DB_SPC.type,fld_idx,decoded,&DB_SPC.seed.l[0]);
      if (fld_typ(SPC_OPT,DB_SPC.type))
      {
    init_sds(DB_SPC.lower.l[1],DB_SPC.intrv.l[1],DB_SPC.order[0],
         DB_SPC.type,fld_idx,decoded,&DB_SPC.seed.l[1]);
        if (strcmp(DB_SPC.type,XYZIX))
      init_sds(DB_SPC.lower.l[2],DB_SPC.intrv.l[2],DB_SPC.order[0],
           DB_SPC.type,fld_idx,decoded,&DB_SPC.seed.l[2]);
      }
    }
  }
  for (rec_idx = 0; no_error && rec_idx < db_spec->num_recs; rec_idx++)
  {                                    
    if (rec_idx % 25000 == 0)
    {
        printf("\nRecord Progress = %ld\n ", rec_idx);
    }
    if (*fptrl)
      fseek(*fptrl,0L,SEEK_SET);
      tim_idx = 0;
      cst_idx = 0;
    for (fld_idx = 0; no_error && fld_idx < num_flds; fld_idx++)
    {                                  
      local_idx = 0;
      switch(DB_SPC.option)
      {
    case OXYZEF :
    case OXYZDR : ;
              break;
    case OXYZEM : ;
              break;
    case OXYZPA :
    case OXYZEL :
    case OXYZR1 : ;
              break;
    case OXYZTN :
    case OXYZTB :
    case OXYZDF : ;
                  ++cst_idx;
              break;
    case OXYZMI : ;
              break;
    case OXYZ9D :
    case OXYZ09 :
    case OXYZ05 : ++local_idx;
    case OXYZTA : ++local_idx;
    case OXYZUS : ++local_idx;
    case OXYZEX : ++local_idx;
    case OXYZAC : ;
               break;
    case OXYZAD :
    case OXYZKD :
    case OXYZED :
    case OINTER : mk_inter(db_spec,decoded[fld_idx],fld_idx,tmp_buf);
              break;
    case OFLTPF :
    case OFLTPE :
    case OFLTPD : mk_float(db_spec,decoded[fld_idx],fld_idx,tmp_buf);
              break;
    case OXYZFX : ;
              break;
    case OXYZNE : ;
              break;
    case OXYZLL :
    case OXYZBR :
    case OXYZ4D :
    case OXYZY4 :
    case OXYZ2D :
    case OXYZY2 :
    case OXYZD2 :
    case OXYZM2 :
    case OXYZM3 :
    case OXYZY1 :
    case OXYZD3 :
    case OXYZM4 :
    case OXYZD4 :
    case OXYZM5 :
    case OXYZY3 :
    case OXYZM6 :
    case OXYZDY :
    case OXYZM1 : ;
              break;
    case OXYZAP :
    case OXYZCO :
    case OXYZPR :
    case OXYZHR : ;
              ++tim_idx;
              break;
    case OXYZIX :
    case OXYZP1 :
    case OXYZP2 :
    case OXYZP3 : ;
              break;
    case OXYZNK :
              break;
    case OXYZIN : ;
              break;
    case ORANDA :
    case ORANDC : mk_ranst(fld_idx,db_spec,decoded[fld_idx],tmp_buf);
              break;
    case OXYZNO : ;
              break;
    case OXYZYF : ;
              break;
    case OXYZBO : ;
              break;
    }
      if (no_error)
    {
    if (DB_SPC.sav_val != NULL)
     strcpy(DB_SPC.sav_val,tmp_buf);
    strcat(tmp_buf,
      fld_idx < (num_flds - 1) ? db_spec->fld_sep : db_spec->rec_sep);
    fputs(tmp_buf,*fpdb);
    file_length = (strlen(tmp_buf));
    }
        file_length_total = file_length_total + file_length;
   }
  }
  closfils(fpdb);
  closfils(fptrl);
  for (idx = 0; idx < 5; idx++)
    {
  }
  {
}
  printf("\nTotal records generated = %'ld\n", db_spec->num_recs);
  printf("\nSingle record size in bytes = %d\n",(file_length_total/db_spec->num_recs));
  printf("\nFile size in bytes = %'d\n",file_length_total);
  time(&end);
  printf("\nStart Time = %s", ctime(&begin));
  printf("\nStop Time = %s", ctime(&end));
  printf("\nProgram completed normally.\n");
}
