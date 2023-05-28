#include "filelib.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {
	int rez = 0;
	char *mainfilename, *string;
	FILE *mainfile, *pofile, *psfile, *ptfile;

	long pos1, pos2;

	while ( (rez = getopt(argc, argv, "ef:s:")) != -1){
		switch (rez) {
		case 'f': {
			mainfilename = makestring(optarg);
			printf("found argument filename = \"%s\".\n", mainfilename);
		 	break;}
		case 's': {
		string = makestring(optarg);
		printf("found argument string = \"%s\".\n", optarg); 
		break;}
		case '?': printf("Error found !\n"); break;
		} 
	}

	printf("Programm started...\n");
	if ((mainfile = fopen(mainfilename, "r")) == 0) {
		printf("Fail to open file: %s\n", mainfilename);
		return -1;
	}

	printf("separator string1 = %s\n\n", string);

	pos1 = findinfile(mainfile, string, 0) - 1;
	fseek(mainfile,0,SEEK_SET);

	if (pos1 == -3) {
		printf("Separator not found\n");
	}
	else {
		mainfilename = formname(mainfilename, 1);
		printf("Output file 1: %s\n", mainfilename);
		pofile = fopen(mainfilename, "w");
		copytofile(mainfile, pofile, 0, pos1);

		fclose(pofile);

		pos2 = findinfile(mainfile, string, pos1) - 1;
		fseek(mainfile,0,SEEK_SET);

		mainfilename = formname(mainfilename, 2);
		psfile = fopen(mainfilename, "w");
		printf("Output file 2: %s\n", mainfilename);


		if (pos2 == -3) {
			printf("Separator not found\nCopying the rest of the file to another file...\n");
			copytofile(mainfile, psfile, pos1+strlen(string), -1);
		}
		else {
			copytofile(mainfile, psfile, pos1+strlen(string), pos2);
			mainfilename = formname(mainfilename, 3);
			ptfile = fopen(mainfilename, "w");
			printf("Output file 3: %s\n\n", mainfilename);
			copytofile(mainfile, ptfile, pos2+strlen(string), -1);
			fclose(ptfile);
		}
		fclose(psfile);	
	}
	free(mainfilename);
	free(string);
	fclose(mainfile);
	
	printf("Programm finished.\n");
}