#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


void PrintFree(char *mas) {
	char *ptr = mas;
		while (*ptr != '\0') {
			putchar(*ptr);
			ptr+=sizeof(char);
		}
	free(mas);
}

char *AddMas(char mas[],  int i) {
	char* ptr = malloc(sizeof(char)*(i));
	char* ret = ptr;

	for (int j = 0; j < i; j++) {
			*ptr = mas[j];
			ptr+=sizeof(char);
		}
	return ret;
}

int main() {
	char* p_mas[1024];
	char *ptr, c;
	char buff[1024];
	int i = 0, j = 0;

	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			buff[i] = '\0';
			p_mas[j++] = AddMas(buff, i);
			i = 0;
		}
		else {
			if (c != ' ' && c != '\t') {
				buff[i++] = c;
			}
		}
	}

	for (int k = 0; k < j; k++) {
		PrintFree(p_mas[k]);
		putchar('\n');

	}
}