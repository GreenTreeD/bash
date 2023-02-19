#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NUM 10

#define FORM(a,b) a+rand()%(b-a+1)

void Fill(int mas[][NUM]) {
	int i,j;

	for (i=0;i<NUM;i++) {
		for (j=0;j<NUM;j++) {
			mas[i][j] = FORM(1,10);
		}

	}
}


void Proc1(int mas[][NUM]) {
int i,j;

	for (i=0;i<NUM;i++) {
		for (j=0;j<i;j++) {
			if (j > (NUM-i-1)) {
				mas[j][NUM-i-1]=0;
				mas[j][i]=0;
		}
		}
	}
}

void Proc2(int mas[][NUM]) {
int i,j,c;

	for (i=0;i<NUM;i++) {
		for (j=0;j<i;j++) {
			if  (j > (NUM-i-1)) {
				c = mas[NUM-i-1][NUM-j-1];
				mas[NUM-i-1][NUM-j-1] = mas[i][j];
				mas[i][j] = c;
		}
		}
	}
}

void Proc3(int mas[][NUM]) {
int i,j,c;

	for (i=0;i<NUM;i++) {
		for (j=0;j<i;j++) {
			if (j > (NUM-i-1)) {
				c = mas[NUM-i-1][j];
				mas[NUM-i-1][j] = mas[i][j];
				mas[i][j] = c;
		}
		}
	}
}
void PrintMas2(int mas[][NUM]){
	int i,j;
	putchar('\n');	
	for (i=0;i<NUM;i++) {
		for (j=0;j<NUM;j++) {
			printf(" %3d ", mas[i][j]);
		}
		putchar('\n');
	}
	putchar('\n');
}


int main() {
	srand(time(NULL));
	int a[NUM][NUM] = {0};
	Fill(a);
	PrintMas2(a);
	Proc1(a);
	PrintMas2(a);
	Proc2(a);
	PrintMas2(a);
}