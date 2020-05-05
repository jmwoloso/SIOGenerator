#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "constsw.h"
#include "structsw.h"
#include "protosw.h"

#define  COPYR1 "Copyright (c) Synthetic IO, Inc."
#define  COPYR2 "Synthetic IO (SIO) is licensed under the terms of the LGPLv3 license"
#define  COPYR3 "SIO Enterprise is a commercial license allowing private forks/mods"
#define  COPYR4 "Send email to info@syntheticio.com for more information"
int           line_num = 0;            
FIL_SPC       db_spec = { '\0' };      
void main(argc,argv)                   
int  argc;                             
char *argv[];                          
{
  unsigned char code_table[TAB_SIZ][TAB_SIZ];
  int           cst_flds = 0;          
  unsigned char **decoded;             
  unsigned char fname[3][BUFSIZ] =     
        { "",GEN_SPC,ENC_FILE };
  FILE          *fpinp = NULL;         
  FILE          *fptab = NULL;         
  FILE          *fptrl = NULL;         
  FILE          *fpdb;                 
  unsigned char key_str[KEY_LEN];      
  int           num_flds  = 0;         
  int           tim_flds  = 0;         
  TIM_REC       *tim_lmts;             
  unsigned char tim_zons[MAX_ZON][4] = 
        { CDT,EDT,MDT,PDT,CST,EST,MST,PST,GMT,ALL };
  int           uni_flds = 0;          
  printf("\n%s\n%s\n%s\n%s\n",COPYR1,COPYR2,COPYR3,COPYR4);
  if (argsg_ok(argc,argv,3,DBG_ERR1,DBG_ERR2,DBG_ERR3,DBG_ERR4,DBG_ERR5,
      fname) &&
    filsopen(fname[1],&fpinp,"r") && filsopen(fname[2],&fptab,"rb"))
  {
    init_cod(&fptab,sizeof(code_table),code_table,key_str);
    if (hdr_okay(fname[1],fpinp,&db_spec,&fpdb))
    {
      if ((decoded =
       (unsigned char**)calloc(MAX_TYP,sizeof(unsigned char *))) == NULL)
    printf("\nUnable to allocate memory in main");
      else if ((tim_lmts = (TIM_REC *)calloc(MAX_TYP,sizeof(TIM_REC))) == NULL)
    printf("\nUnable to allocate memory in main");
      else if (flds_ok(&fpinp,fname[1],tim_zons,&db_spec,&num_flds,decoded,
               tim_lmts,&tim_flds,&cst_flds,&fptrl,&uni_flds))
      {
    if (num_flds == 0)
      printf("\nNo field specifications in input spec file");
    else if ((decoded = (unsigned char**)realloc(decoded,num_flds *
                 sizeof(unsigned char *))) == NULL)
      printf("\nUnable to allocate memory in main");
    else if ((tim_lmts =
        (TIM_REC *)realloc(tim_lmts,tim_flds * sizeof(TIM_REC)))
         == NULL && tim_flds > 0)
      printf("\nUnable to allocate memory in main");
    else
    {
         bild_db(tim_lmts,&fpdb,&db_spec,num_flds,code_table,key_str,decoded,
          &fptrl,tim_zons);
    }
      }
    }
  }
}
