#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "constsw.h"
#include "structsw.h"
#include "protosw.h"
int hdr_okay(fname,fpinp,db_spec,fpdb) 
unsigned char fname[];                 
FILE          *fpinp;                  
FIL_SPC *db_spec;                      
FILE    **fpdb;                        
{
  extern int    line_num;              
  int           idx = -1;              
  int           no_error;              
  unsigned char inp_text[255] =     
			 { '\0' };
  do                                   
  {
    ++line_num;
  } while ((no_error = (int)fgets(inp_text,255,fpinp)) &&
	    !not_blnk(inp_text));
  if (!no_error)
    printf("\nSpecification file %s is empty",fname);
  else
  {                                    
    strcpy(db_spec->file_name,inp_text);
    db_spec->file_name[strlen(db_spec->file_name)-1] = '\0';
    while (isspace(db_spec->file_name[++idx]));
    strcpy(db_spec->file_name,db_spec->file_name+idx);
    strcpy(db_spec->file_name,db_spec->file_name);
    strcat(db_spec->file_name,GEN_SUF);
    if (no_error = filsopen(db_spec->file_name,fpdb,"w"))
    {
      do                               
      {
	++line_num;
      } while ((no_error = (int)fgets(inp_text,BUFSIZ,fpinp)) &&
		!not_blnk(inp_text));
      if (!no_error)
	PRINT_ERR("Illegal number of data records");
      else if (!(no_error = (sscanf(inp_text,"%ld",&db_spec->num_recs) == 1 &&
			     db_spec->num_recs > 0                          &&
			     db_spec->num_recs <= MAX_OUT)))
	PRINT_ERR("Exceeded maximum number of data records to generate");
      else
      {                                
	do                             
	{
	  ++line_num;
	} while ((no_error = (int)fgets(inp_text,BUFSIZ,fpinp)) &&
		  !not_blnk(inp_text));
	if (!no_error)
	  PRINT_ERR("No record type specified");
	else
	{
	  idx = -1;
	  while (isspace(inp_text[++idx]));
	  if (!(no_error =
		((db_spec->rec_typ = toupper(inp_text[idx])) == VAR_LEN ||
		  db_spec->rec_typ == FIX_LEN)))
	    PRINT_ERR("Illegal record type");
	  else
	  {                            
	    do                         
	    {
	      ++line_num;
	    } while ((no_error = (int)fgets(inp_text,BUFSIZ,fpinp)) &&
		      !not_blnk(inp_text));
	    if (!no_error)
	      PRINT_ERR("No field separator found");
	    else if (!(no_error =
		       ((db_spec->fld_sep[0] = set_delm(inp_text)) != BAD_SEP)))
	      PRINT_ERR("Illegal field separator found");
	    else
	    {                          
	      do                       
	      {
		++line_num;
	      } while ((no_error = (int)fgets(inp_text,BUFSIZ,fpinp)) &&
			!not_blnk(inp_text));
	      if (!no_error)
		PRINT_ERR("No record separator specified");
	      else if (!(no_error =
			 ((db_spec->rec_sep[0] = set_delm(inp_text)) != BAD_SEP)))
		PRINT_ERR("Illegal record separator found");
	    }
	  }
	}
      }
    }
  }
  return(no_error);
}
