/*
Macros definitions, etc.
*/
				       /* usage messages                   */

#define DBG_ERR1 "             \n"
#define DBG_ERR2 "             \n"
#define DBG_ERR3 "             \n"
#define DBG_ERR4 "             \n"
#define DBG_ERR5 "             \n"
#define GEN_ERR  "             \n"

				       /* macros for ease of reference     */
#define DB_SP db_spec->fld_spc
#define DB_SPEC DB_SP[*num_flds]
#define DB_SPC db_spec->fld_spc[fld_idx]
#define FPBIN  db_spec->fpbin[DB_SPC.file_idx]
#define TRLR_RC trailer[DB_SPC.file_idx]
#define DB_TYPE db_spec->fld_spc[jdx].type

				       /* the following are used by the    */
				       /*   randflt() function             */
#define IM1  2147483563
#define IM2  2147483399
#define AM   (1.0 / IM1)
#define IMM1 (IM1 - 1)
#define IA1  40014
#define IA2  40692
#define IQ1  53668
#define IQ2  52774
#define IR1  12211
#define IR2  3791
#define NTAB 32
#define NDIV (1 + IMM1 / NTAB)
#define EPS  1.2e-7
#define RNMX (1.0 - EPS)

#define UNI_FIL      "tempu_"         /* placeholder future enhancement    */

#define ENC_FILE "enctable"           /* default file name for encryption  */

#define GEN_SPC   "sample.spf"        /* spec file                         */


#define GEN_SUF          ""           /* template file suffix              */

#define PERIOD              '.'       /* file suffix delimiter             */
#define NO_FILE              -1       /* indicates no file association     */

#define NUM_FLD               6        /* maximum number of fields         */

#define NUM_SEP               9        /* field separators                 */


#define MAX_ZON              10        /* placeholder future enhancement   */
#define ALL               "ALL"        /*                                  */
#define CDT               "CDT"        /*                                  */
#define EDT               "EDT"        /*                                  */
#define MDT               "MDT"        /*                                  */
#define PDT               "PDT"        /*                                  */
#define CST               "CST"        /*                                  */
#define EST               "EST"        /*                                  */
#define MST               "MST"        /*                                  */
#define PST               "PST"        /*                                  */
#define GMT               "GMT"        /*                                  */

                                       /* placeholder future enhancement   */

#define CST_OPT               1        /* for future use                   */
#define CTY_STA               2        /* for future use                   */
#define DAT_OPT               3        /* for future use                   */
#define DEC_OPT               4        /* integer type                     */
#define JUL_OPT               5        /* for future use                   */
#define PHN_OPT               6        /* for future use                   */
#define RAN_OPT               7        /* random character string type     */
#define SPC_OPT               8        /* for future use                   */
#define TIM_OPT               9        /* for future use                   */
#define YR_LAST              10        /* for future use                   */
#define ZIP_OPT              11        /* for future use                   */
#define YR4_OPT              12        /* for future use                   */
#define FLT_OPT              13        /* floating point number type       */


#define NPA_OFF              0         /* for future use                   */
#define NXX_OFF              5         /* for future use                   */
#define CTY_OFF              10        /* for future use                   */
#define STA_OFF              35        /* for future use                   */
#define ZIP_OFF              37        /* for future use                   */


#define NAM_OFF               0        /* for future use                   */
#define SEX_OFF              15        /* for future use                   */

#define APS_COD             'A'        /* symbol for apostrophe separator  */
#define APS_SEP            '\''        /* field/record separator character */
#define CMA_COD             'C'        /* symbol for comma separator       */
#define CMA_SEP             ','        /* field/record separator character */
#define LIN_COD             'L'        /* symbol for newline separator     */
#define LIN_SEP            '\n'        /* newline separator character      */
#define NUL_COD             'N'        /* flag in template file indicating */


#define NUL_SEP            '\0'        /* field/record separator character */
#define PIP_COD             'P'        /* symbol for pipe separator        */
#define PIP_SEP             '|'        /* field/record separator character */
#define SLH_COD             'S'        /* symbol for slash separator       */
#define SLH_SEP             '/'        /* field/record separator character */
#define DSH_SEP             '-'        /* separator for dates              */
#define CLN_SEP             ':'        /* separator for times              */
#define PRD_SEP             '.'        /* separator for times              */
#define BAD_SEP             'B'        /* bad separator flag               */
#define VAR_LEN             'V'        /* flag for variable length records */
#define FIX_LEN             'F'        /* flag for fixed length records    */
#define RAN_ORD             'R'        /* random order flag for numeric    */
#define SEQ_ORD             'S'        /* sequential order flag for numeric*/
#define UNI_ORD             'U'        /* unique order flag                */
#define BLNK1               ' '        /* separator character between file */


#define TAB_SEP             '\t'       /* SQL import delimiters            */
#define TAB_COD             'T'
#define ZERO                '0'        /* used for padding numeric fields  */
                                       /*   with leading zeroes            */
#define DASH                "-"        /* used as a separator in various   */
                                       /*   fields, such as ZIP9D          */
#define FLD_DLM             '|'        /* field separator character for    */


#define FLD_LEN               6        /* field fill type name length      */

#define KEY_LEN             81         /* maximum length of key string     */

#define KEY_STR "The Grateful Dead"    /* encryption/decryption code string*/
#define SHIFT                13        /* number of positions to shift     */

#define TAB_SIZ             128        /* size of encryption table         */
#define MAX_DEC               6        /* maximum number of decimal places */

#define MAX_FLT              17        /* maximum number of decimal places */

#define MAX_EXP            4930        /* maximum exponent size for a      */

#define MAX_RPT           32767        /* maximum repeat count             */
#define MAX_RND      999999999L        /* constants for random number gen- */
#define MAX_DIV           32768        /*   eration of integers            */
#define MAX_MLT       331415821        /* placeholder future enhancement   */
#define MAX_FLD             81         /* maximum length for any field 80  */
#define MAX_FIL               5        /* for future use                   */

#define MAX_ALF             26L        /* number of letters in alphabet    */
#define MAX_HRS              23        /* for future use                   */
#define MAX_MIN              59        /* for future use                   */
#define MAX_SEC              59        /* for future use                   */
#define MAX_TIM          240000        /* for future use                   */
#define MAX_TYP             255        /* maximum number of field types in */

#define MAX_OUT         1000000        /* maximum number of records        */



#define NUM_TYP              59

#define INTER           "INTER"        /* positive-negative integer        */
#define FLTPF           "FLTPF"        /* floating point number X.XXX      */
#define FLTPE           "FLTPE"        /* floating point number X.XXXE+NN  */
#define FLTPD           "FLTPD"        /* floating point number X.XXXD+NN  */
#define RANDC           "RANDC"        /* random alphabetic string         */
#define RANDA           "RANDA"        /* random alphanumeric string       */
#define XINTER               -1        /* positive-negative integer        */
#define XFLTPF               -1        /* floating point number X.XXX      */
#define XFLTPE               -1        /* floating point number X.XXXE+NN  */
#define XFLTPD               -1        /* floating point number X.XXXD+NN  */
#define XRANDC               -1        /* random alphabetic string         */
#define XRANDA               -1        /* random alphanumeric string       */
#define OINTER               12        /* positive-negative integer        */
#define OFLTPF               13        /* floating point number X.XXX      */
#define OFLTPE               14        /* floating point number X.XXXE+NN  */
#define OFLTPD               15        /* floating point number X.XXXD+NN  */
#define ORANDC               38        /* random alphabetic string         */
#define ORANDA               39        /* random alphanumeric string       */
#define INTER_LN             12        /* positive-negative integer        */
#define FLTPF_LN             80        /* floating point number X.XXX      */
#define FLTPE_LN             80        /* floating point number X.XXXE+NN  */
#define FLTPD_LN             80        /* floating point number X.XXXD+NN  */
#define RANDC_LN             80        /* random alphabetic string         */
#define RANDA_LN             80        /* random alphanumeric string       */


                                       /* placeholder future enhancement   */

#define XYZEF           "XYZEF"        /* for future use                   */
#define XYZDR           "XYZDR"        /* for future use                   */
#define XYZAC           "XYZAC"        /* for future use                   */
#define XYZEX           "XYZEX"        /* for future use                   */
#define XYZUS           "XYZUS"        /* for future use                   */
#define XYZTA           "XYZTA"        /* for future use                   */
#define XYZ05           "XYZ05"        /* for future use                   */
#define XYZ09           "XYZ09"        /* for future use                   */
#define XYZ9D           "XYZ9D"        /* for future use                   */
#define XYZEL           "XYZEL"        /* for future use                   */
#define XYZMI           "XYZMI"        /* for future use                   */
#define XYZR1           "XYZR1"        /* for future use                   */
#define XYZAD           "XYZAD"        /* for future use                   */
#define XYZKD           "XYZKD"        /* for future use                   */
#define XYZED           "XYZED"        /* for future use                   */
#define XYZEM           "XYZEM"        /* for future use                   */
#define XYZFX           "XYZFX"        /* for future use                   */
#define XYZNO           "XYZNO"        /* for future use                   */
#define XYZPA           "XYZPA"        /* for future use                   */
#define XYZNE           "XYZNE"        /* for future use                   */
#define XYZLL           "XYZLL"        /* for future use                   */
#define XYZBR           "XYZBR"        /* for future use                   */
#define XYZDY           "XYZDY"        /* for future use                   */
#define XYZM1           "XYZM1"        /* for future use                   */
#define XYZD2           "XYZD2"        /* for future use                   */
#define XYZM2           "XYZM2"        /* for future use                   */
#define XYZM3           "XYZM3"        /* for future use                   */
#define XYZY1           "XYZY1"        /* for future use                   */
#define XYZHR           "XYZHR"        /* for future use                   */
#define XYZAP           "XYZAP"        /* for future use                   */
#define XYZCO           "XYZCO"        /* for future use                   */
#define XYZPR           "XYZPR"        /* for future use                   */
#define XYZNK           "XYZNK"        /* for future use                   */
#define XYZIN           "XYZIN"        /* for future use                   */
#define XYZD3           "XYZD3"        /* for future use                   */
#define XYZM4           "XYZM4"        /* for future use                   */
#define XYZD4           "XYZD4"        /* for future use                   */
#define XYZM5           "XYZM5"        /* for future use                   */
#define XYZY3           "XYZY3"        /* for future use                   */
#define XYZM6           "XYZM6"        /* for future use                   */
#define XYZ4D           "XYZ4D"        /* for future use                   */
#define XYZY4           "XYZY4"        /* for future use                   */
#define XYZ2D           "XYZ2D"        /* for future use                   */
#define XYZY2           "XYZY2"        /* for future use                   */
#define XYZP1           "XYZP1"        /* for future use                   */
#define XYZP2           "XYZP2"        /* for future use                   */
#define XYZP3           "XYZP3"        /* for future use                   */
#define XYZIX           "XYZIX"        /* for future use                   */
#define XYZTN           "XYZTN"        /* for future use                   */
#define XYZTB           "XYZTB"        /* for future use                   */
#define XYZYF           "XYZYF"        /* for future use                   */
#define XYZBO           "XYZBO"        /* for future use                   */
#define XYZDF           "XYZDF"        /* for future use                   */

#define XXYZEF                0        /* for future use                   */
#define XXYZDR                0        /* for future use                   */
#define XXYZAC                3        /* for future use                   */
#define XXYZEX                3        /* for future use                   */
#define XXYZUS                3        /* for future use                   */
#define XXYZTA                3        /* for future use                   */
#define XXYZ05                3        /* for future use                   */
#define XXYZ09                3        /* for future use                   */
#define XXYZ9D                3        /* for future use                   */
#define XXYZEL                1        /* for future use                   */
#define XXYZMI               -1        /* for future use                   */
#define XXYZR1                2        /* for future use                   */
#define XXYZAD               -1        /* for future use                   */
#define XXYZKD               -1        /* for future use                   */
#define XXYZED               -1        /* for future use                   */
#define XXYZEM                0        /* for future use                   */
#define XXYZFX               -1        /* for future use                   */
#define XXYZNO                3        /* for future use                   */
#define XXYZPA                4        /* for future use                   */
#define XXYZNE                3        /* for future use                   */
#define XXYZLL               -1        /* for future use                   */
#define XXYZBR               -1        /* for future use                   */
#define XXYZDY               -1        /* for future use                   */
#define XXYZM1               -1        /* for future use                   */
#define XXYZD2               -1        /* for future use                   */
#define XXYZM2               -1        /* for future use                   */
#define XXYZM3               -1        /* for future use                   */
#define XXYZY1               -1        /* for future use                   */
#define XXYZHR               -1        /* for future use                   */
#define XXYZAP               -1        /* for future use                   */
#define XXYZCO               -1        /* for future use                   */
#define XXYZPR               -1        /* for future use                   */
#define XXYZNK               -1        /* for future use                   */
#define XXYZIN               -1        /* for future use                   */
#define XXYZD3               -1        /* for future use                   */
#define XXYZM4               -1        /* for future use                   */
#define XXYZD4               -1        /* for future use                   */
#define XXYZM5               -1        /* for future use                   */
#define XXYZY3               -1        /* for future use                   */
#define XXYZM6               -1        /* for future use                   */
#define XXYZ4D               -1        /* for future use                   */
#define XXYZY4               -1        /* for future use                   */
#define XXYZ2D               -1        /* for future use                   */
#define XXYZY2               -1        /* for future use                   */
#define XXYZP1               -1        /* for future use                   */
#define XXYZP2               -1        /* for future use                   */
#define XXYZP3               -1        /* for future use                   */
#define XXYZIX               -1        /* for future use                   */
#define XXYZTN               -1        /* for future use                   */
#define XXYZTB               -1        /* for future use                   */
#define XXYZYF               -1        /* for future use                   */
#define XXYZBO               -1        /* for future use                   */
#define XXYZDF               -1        /* for future use                   */
#define OXYZEF                0        /* for future use                   */
#define OXYZDR                1        /* for future use                   */
#define OXYZAC                2        /* for future use                   */
#define OXYZEX                3        /* for future use                   */
#define OXYZUS                4        /* for future use                   */
#define OXYZTA                5        /* for future use                   */
#define OXYZ05                6        /* for future use                   */
#define OXYZ09                7        /* for future use                   */
#define OXYZ9D                8        /* for future use                   */
#define OXYZEL                9        /* for future use                   */
#define OXYZMI               10        /* for future use                   */
#define OXYZR1               11        /* for future use                   */
#define OXYZAD               16        /* for future use                   */
#define OXYZKD               17        /* for future use                   */
#define OXYZED               18        /* for future use                   */
#define OXYZEM               19        /* for future use                   */
#define OXYZFX               20        /* for future use                   */
#define OXYZNO               21        /* for future use                   */
#define OXYZPA               22        /* for future use                   */
#define OXYZNE               23        /* for future use                   */
#define OXYZLL               24        /* for future use                   */
#define OXYZBR               25        /* for future use                   */
#define OXYZDY               26        /* for future use                   */
#define OXYZM1               27        /* for future use                   */
#define OXYZD2               28        /* for future use                   */
#define OXYZM2               29        /* for future use                   */
#define OXYZM3               30        /* for future use                   */
#define OXYZY1               31        /* for future use                   */
#define OXYZHR               32        /* for future use                   */
#define OXYZAP               33        /* for future use                   */
#define OXYZCO               34        /* for future use                   */
#define OXYZPR               35        /* for future use                   */
#define OXYZNK               36        /* for future use                   */
#define OXYZIN               37        /* for future use                   */
#define OXYZD3               40        /* for future use                   */
#define OXYZM4               41        /* for future use                   */
#define OXYZD4               42        /* for future use                   */
#define OXYZM5               43        /* for future use                   */
#define OXYZY3               44        /* for future use                   */
#define OXYZM6               45        /* for future use                   */
#define OXYZ4D               46        /* for future use                   */
#define OXYZY4               47        /* for future use                   */
#define OXYZ2D               48        /* for future use                   */
#define OXYZY2               49        /* for future use                   */
#define OXYZP1               50        /* for future use                   */
#define OXYZP2               51        /* for future use                   */
#define OXYZP3               52        /* for future use                   */
#define OXYZIX               53        /* for future use                   */
#define OXYZTN               54        /* for future use                   */
#define OXYZTB               55        /* for future use                   */
#define OXYZYF               56        /* for future use                   */
#define OXYZBO               57        /* for future use                   */
#define OXYZDF               58        /* for future use                   */
#define XYZEF_LN             23        /* for future use                   */
#define XYZDR_LN             23        /* for future use                   */
#define XYZAC_LN             40        /* for future use                   */
#define XYZEX_LN             40        /* for future use                   */
#define XYZUS_LN             40        /* for future use                   */
#define XYZTA_LN             40        /* for future use                   */
#define XYZ05_LN             70        /* for future use                   */
#define XYZ09_LN             70        /* for future use                   */
#define XYZ9D_LN             70        /* for future use                   */
#define XYZEL_LN             23        /* for future use                   */
#define XYZMI_LN              2        /* for future use                   */
#define XYZR1_LN             40        /* for future use                   */
#define XYZAD_LN             12        /* for future use                   */
#define XYZKD_LN             24        /* for future use                   */
#define XYZED_LN             24        /* for future use                   */
#define XYZEM_LN             23        /* for future use                   */
#define XYZFX_LN             23        /* for future use                   */
#define XYZNO_LN             70        /* for future use                   */
#define XYZPA_LN             33        /* for future use                   */
#define XYZNE_LN             70        /* for future use                   */
#define XYZLL_LN             18        /* for future use                   */
#define XYZBR_LN             12        /* for future use                   */
#define XYZDY_LN              7        /* for future use                   */
#define XYZM1_LN              7        /* for future use                   */
#define XYZD2_LN              7        /* for future use                   */
#define XYZM2_LN              7        /* for future use                   */
#define XYZM3_LN              7        /* for future use                   */
#define XYZY1_LN              7        /* for future use                   */
#define XYZHR_LN              7        /* for future use                   */
#define XYZAP_LN              9        /* for future use                   */
#define XYZCO_LN              7        /* for future use                   */
#define XYZPR_LN              7        /* for future use                   */
#define XYZNK_LN              2        /* for future use                   */
#define XYZIN_LN             80        /* for future use                   */
#define XYZD3_LN              9        /* for future use                   */
#define XYZM4_LN              9        /* for future use                   */
#define XYZD4_LN              9        /* for future use                   */
#define XYZM5_LN              9        /* for future use                   */
#define XYZY3_LN              9        /* for future use                   */
#define XYZM6_LN              9        /* for future use                   */
#define XYZ4D_LN              8        /* for future use                   */
#define XYZY4_LN              8        /* for future use                   */
#define XYZ2D_LN              7        /* for future use                   */
#define XYZY2_LN              7        /* for future use                   */
#define XYZP1_LN             24        /* for future use                   */
#define XYZP2_LN             24        /* for future use                   */
#define XYZP3_LN             16        /* for future use                   */
#define XYZIX_LN             23        /* for future use                   */
#define XYZTN_LN             80        /* for future use                   */
#define XYZTB_LN             80        /* for future use                   */
#define XYZYF_LN             80        /* for future use                   */
#define XYZBO_LN             80        /* for future use                   */
#define XYZDF_LN             80        /* for future use                   */

