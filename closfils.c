#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void closfils(fptr)
FILE **fptr;
{
    if (*fptr)
    fclose(*fptr);
}
