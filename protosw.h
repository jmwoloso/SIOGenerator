/*                           Macro Definitions                             */

/* Prints error messages in the spec file                                  */
#define PRINT_ERR(x) printf("\n%s on line %d in file %s",x,line_num,fname)
/*  Determines if a value is within a given range.                         */
#define IN_RANG(lower,upper,chk_val) (chk_val >= lower && chk_val <= upper)
/*  Determines if the interval is correct for a given range.               */
#define INTV_OK(lower,upper,intrv) (lower <= upper && intrv >= 0) || \
				   (lower >= upper && intrv < 0)

/*                          Function Prototypes                            */


  int  argsg_ok(int argc, char*argv[],
		int max_args,unsigned char msg1[],unsigned char msg2[],
		unsigned char msg3[],unsigned char msg4[],
		unsigned char msg5[],unsigned char fname[][BUFSIZ]);
  void bild_db(TIM_REC tim_lmts[],FILE **fpdb,
	       FIL_SPC *db_spec,int num_flds,
	       unsigned char code_table[][TAB_SIZ],unsigned char key_str[],
	       unsigned char **decoded,FILE **fptrl,
	       unsigned char tim_zons[][4]);
  int  chk_nlt(int *num_flds,
	       FIL_SPC *db_spec,char err_buf[]);  
  int  chk_ran(int *num_flds,
	       FIL_SPC *db_spec,char err_buf[]);
  int  ck_olui(int *num_flds,
	       unsigned char tim_zons[][4],FIL_SPC *db_spec,char err_buf[]);
  void closfils(FILE **fptr);
  int  cnt_chr(unsigned char decoded[],
	     int flnth,unsigned char chr_typ,int *lst_pos);
  int  cnt_sep(unsigned char inp_txt[],
           unsigned char **ptr);
  int  fld_typ(int option,
	       unsigned char type[]);
  int  filsopen(unsigned char *fname,
		 FILE **fp,unsigned char *mode);
   int  flds_ok(FILE **fpinp,
	       unsigned char fname[],unsigned char tim_zons[][4],
	       FIL_SPC *db_spec,int *num_flds,unsigned char **decoded,
	       TIM_REC tim_lmts[],int *tim_flds,int *cst_flds,FILE **fptrl,
	       int *uni_flds);
  int  hdr_okay(unsigned char fname[],
		FILE *fpinp,FIL_SPC *db_spec,FILE **fpdb);
  void init_cod(FILE **fptab,int size,
		unsigned char code_table[][TAB_SIZ],unsigned char key_str[]);
  void init_sds(long lower,
		long intrv,unsigned char order,unsigned char type[],
		int fld_idx,unsigned char **decoded,long *seed);
  int  in_seq(FIL_SPC *db_spec,
          int num_flds);
  void jst_alfa(
		unsigned char decoded[],int flnth,int slnth,
		unsigned char rec_typ,unsigned char *tmp_buf);
  void jst_nmrc(
		unsigned char decoded[],int flnth,int slnth,
		unsigned char type[],unsigned char rec_typ,
		unsigned char *tmp_buf);
  int  mk_blank(FIL_SPC *db_spec,
		int fld_idx,unsigned char decoded[],unsigned char *tmp_buf);
  void mk_float(FIL_SPC *db_spec,
		unsigned char decoded[],int fld_idx,unsigned char *tmp_buf);
  void mk_inter(FIL_SPC *db_spec,
		unsigned char decoded[],int fld_idx,unsigned char *tmp_buf);
  void mk_ranst(int fld_idx,
		FIL_SPC *db_spec,unsigned char decoded[],
		unsigned char *tmp_buf);
  long mult(long p,long q);
  unsigned char not_blnk(
			 unsigned char inp_txt[]);
  double pow_10(int exp);
  float randflt(long *idum);
  long randmar(long r,long *seed);
  int  rd_flds(unsigned char inp_txt[],
	       int *num_flds,unsigned char *pt1,FIL_SPC *db_spec,
	       char err_buf[],int *num_sep,unsigned char **ptr);
  int  rd_seed(unsigned char *ptr,
	       int *num_flds,int num_sep,FIL_SPC *db_spec,char err_buf[],
	       int *no_mem_err);
  void set_bnds(int option,long *lower,
        long *upper,
		long *intrv);
  int  set_buf(FIL_SPC *db_spec,
           int idx,
	       unsigned char **decoded);
  unsigned char set_delm(
       unsigned char inp_text[]);
  void set_tab(unsigned char str_buf[]);
  void set_trlr(int num_flds,
        FIL_SPC *db_spec,
        TRL_REC trailer[]);
  int  set_unif(int fld_idx,
        FIL_SPC *db_spec,
		int *uni_flds);
  void skp_fld(unsigned char inp_txt[],
           unsigned char **pt1);
  int  srt_flds(FIL_SPC *db_spec,
                       unsigned char **decoded,int *num_flds);

