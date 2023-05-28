#include "filelib.h"

#include <string.h>
#include <stdlib.h>

void copytofile(FILE * p, FILE * n, long stpos, long endpos) {
	FILE *tmp1 = p, *tmp2 = n;
	
	if (endpos < 0) {
		fseek(tmp1,0,SEEK_END);
		endpos = ftell(tmp1);
		fseek(tmp1,0,SEEK_SET);
	}
	if (stpos < 0) stpos = 0;
	fseek (tmp1,stpos,SEEK_SET);
	//printf("stpos = %d\n endpos = %d\nСОДЕРЖИМОЕ:\n", stpos, endpos);
	for (long i = stpos; i < endpos; i++) {
		fputc(fgetc(tmp1), tmp2 );
	}
}

long findinfile(FILE *p_n, char * string, long stpos) {
	FILE *p = p_n;
	char ch, *temp;
	temp = string;
	long pos = 0;
	int flag = 0, done = 0;
	fseek(p,0,SEEK_SET);
	if (stpos != 0) {fseek(p,stpos+strlen(string)-1,SEEK_SET);}
	ch = fgetc(p);


	while ((ch != EOF)&&(done == 0)){
		if (flag == 0) {
			if (*temp == ch) {
				pos = ftell(p);
				temp++;
				flag = 1;
			}
		}
		else if (flag == 1){
			if (*temp == '\0') {done = 1; continue;}
			else if (*temp == ch) {temp++;}
			else if (*temp != ch) {flag = 0; temp = string;}
		}
		ch = fgetc(p);
	}
	if (done == 0){pos = -2;}
	fseek(p,0,SEEK_SET);

	return pos;
}

char * makestring(char * cp) {
	char * temp = NULL;

	temp = (char *)malloc(sizeof(int) * strlen(cp));
	if (temp == NULL) return NULL;
	strcpy(temp, cp);
	return temp;
}

char * formname(char * init, int mode) {
	char * temp = NULL;
	char *fullstr = NULL;
	

	switch(mode) {
		case 1: {
			fullstr = (char *) malloc((strlen(init)+10)*sizeof(int));
			if (fullstr == NULL) return NULL;
			if((temp = strchr(init, '.')) != NULL) {
				*temp='\0';
				temp++;
			}
			
			strcat(fullstr, init);
			strcat(fullstr, "_part1");
			if (temp != NULL) strcat(fullstr, ".");
			strcat(fullstr, temp);
			free(init);
			break;
			}
		default: {
			if((temp = strchr(init, '.')) != NULL) {
				temp--;
			}
			else{
				temp = strchr(init, '\0');
			}
			*temp = (char)('0'+mode);
			fullstr = init;
			break;}
	}
	return fullstr;

}