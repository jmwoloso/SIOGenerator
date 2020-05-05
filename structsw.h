/* data structures */
typedef struct
{
  int hrs_yrs[2];
  int mins_mos[2];
  int secs_dys[2];
} TIM_REC;

typedef struct
{
  int  fld_len[NUM_FLD];
  int  num_fld;
  long num_recs;
  int  rec_len;
} TRL_REC;

typedef union
{
  long          l[3];
  long double   d;
  short         f[6];
  unsigned char c[12];
} LNG_DBL;

typedef struct
{
  FILE          *fpuni;

  int           idx;
  int           option;



  int           file_idx;
  unsigned char type[FLD_LEN];
  int           lnth;

  unsigned char order[2];
  LNG_DBL       lower;
  LNG_DBL       upper;
  LNG_DBL       intrv;
  int           num_dec;
  LNG_DBL       seed;


  int           rpt_lmt;

  int           rpt_idx;
  unsigned char *sav_val;

  unsigned char tim_zon[4];
} FLD_DEF;

typedef struct
{
  unsigned char file_name[BUFSIZ];
  long          num_recs;
  FILE          *fpbin[MAX_FIL];
  unsigned char rec_typ;
  unsigned char fld_sep[2];
  unsigned char rec_sep[2];
  FLD_DEF       fld_spc[MAX_TYP];
} FIL_SPC;

