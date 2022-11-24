#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NUM 10

void Fill(int mas[][NUM]) {
	int i,j;

	for (i=0;i<NUM;i++) {
		for (j=0;j<NUM;j++) {
			mas[i][j] = 1 + rand()%10;
		}

	}
}

void Fill1(int mas[][NUM]) {
	int i,j,k=0;

	for (i=0;i<NUM;i++) {
		for (j=0;j<NUM;j++) {
			mas[i][j] = k;
			k++;
		}
	}
}

void Proc1(int mas[][NUM]) {
int i,j;

	for (i=0;i<NUM;i++) {
		for (j=0;j<NUM;j++) {
			if ((j < i) && (j > (NUM-i-1))) {
				mas[j][NUM-i-1]=0;
				mas[j][i]=0;
		}
		}
	}
}

void Proc2(int mas[][NUM]) {
int i,j,c;

	for (i=0;i<NUM;i++) {
		for (j=0;j<NUM;j++) {
			if ((j < i) && (j > (NUM-i-1))) {
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
		for (j=0;j<NUM;j++) {
			if ((j < i) && (j > (NUM-i-1))) {
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
	Fill1(a);
	PrintMas2(a);
	Proc1(a);
	PrintMas2(a);
	Proc2(a);
	PrintMas2(a);
}