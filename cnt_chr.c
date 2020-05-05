#include <ctype.h>
int cnt_chr(decoded,flnth,chr_typ,lst_pos)
unsigned char decoded[];               
int           flnth;                   
unsigned char chr_typ;                 
int           *lst_pos;                
{
  int idx;                             
  int count = 0;                       
  switch(chr_typ)
  {
    case 'u' : for (idx = 0; idx < flnth; idx++)
		 if (isupper(decoded[idx]))
		 {
		   ++count;
		   *lst_pos = idx;
		 }
	       break;
    case 'l' : for (idx = 0; idx < flnth; idx++)
		 if (islower(decoded[idx]))
		 {
		   ++count;
		   *lst_pos = idx;
		 }
	       break;
    case 'd' : for (idx = 0; idx < flnth; idx++)
		 if (isdigit(decoded[idx]))
		 {
		   ++count;
		   *lst_pos = idx;
		 }
  }
  return(count);
}
