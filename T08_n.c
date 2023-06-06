#include <stdio.h>
#include <stdlib.h>

void SwapAll(FILE *file, long pos) {
	char byte1, byte2;

	for (long i = 0; i < (pos/2); i++){
		fseek(file, i, SEEK_SET);
		fread(&byte1, sizeof(char), 1, file);
		fseek(file, -i-1, SEEK_END);
		fread(&byte2, sizeof(char), 1, file);

		fseek(file, i, SEEK_SET);
		fwrite(&byte2, sizeof(char), 1, file);
		fseek(file, -i-1, SEEK_END);
		fwrite(&byte1, sizeof(char), 1, file);
		//printf("%c %c\n", byte1, byte2);
	}
	fseek(file, 0, SEEK_SET);
}

void Swap(long stpos, long endpos, FILE* file) {

char byte1, byte2;

	for (long i = 0; i < ((endpos-stpos)/2); i++)
	{
		fseek(file, stpos+i, SEEK_SET);
		fread(&byte1, sizeof(char), 1, file);
		fseek(file, endpos-i, SEEK_SET);
		fread(&byte2, sizeof(char), 1, file);

		fseek(file, stpos+i, SEEK_SET);
		fwrite(&byte2, sizeof(char), 1, file);
		fseek(file, endpos-i, SEEK_SET);
		fwrite(&byte1, sizeof(char), 1, file);
		//printf("%c %c\n", byte1, byte2);
	}
	fseek(file, 0, SEEK_SET);
}

void SwapParts(FILE * file, long pos){
	char byte1, byte2;
	int j = (pos%2 == 1) ? ((pos/2)+1) : (pos/2);

	for (long i = 0; i < (pos/2); i++){
		fseek(file, i, SEEK_SET);
		fread(&byte1, sizeof(char), 1, file);
		fseek(file, j+i, SEEK_SET);
		fread(&byte2, sizeof(char), 1, file);

		fseek(file, i, SEEK_SET);
		fwrite(&byte2, sizeof(char), 1, file);
		fseek(file, j+i, SEEK_SET);
		fwrite(&byte1, sizeof(char), 1, file);
		//printf("%c %c\n", byte1, byte2);
	}
	fseek(file, 0, SEEK_SET);
}


int main(int argc, char** argv) {
	
	FILE *f;
	long pos;
	
	f = fopen(argv[1], "r+");
	if (!f) {
	printf("can't open file\n");
	return -1;}
	fseek(f,0,SEEK_END);
	pos = ftell(f);
	fseek(f,0,SEEK_SET);
	//printf("%ld\n", pos);
	//printf("ПЕРВАЯ ЗАМЕНА\n");
	//Swap(0,pos/2-1, f);
	//printf("ВТОРАЯ ЗАМЕНА\n");
	/*if (pos %2 != 0) {
	Swap(pos/2+1, pos-1, f);}
	else {
	Swap(pos/2, pos-1, f);}*/

	//SwapParts(f, pos);
	SwapAll(f,pos);
	fclose(f);	
}
