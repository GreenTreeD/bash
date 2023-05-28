#include <stdlib.h>
#include <stdio.h>

#ifndef __FILELIBg__
#define __FILELIBg__

void copytofile(FILE * p, FILE * n, long stpos, long endpos);
long findinfile(FILE * p, char * string, long stpos);
char * formname(char * init, int mode);
char * makestring(char * cp);


#endif