#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NUM 10

#define FORM(a,b) a+rand()%(b-a+1)

void Fill(int mas[][NUM]) {
	int i,j;

	for (i=0;i<NUM;i++) {
		for (j=0;j<NUM;j++) {
			mas[i][j] = FORM(1,15);
		}
	}
}


void Swapping_Elem(int mas[][NUM]) {
int i,j,c;

	for (i=0;i<NUM;i++) {
		for (j=0;j<i;j++) {
			if  (j > (NUM-i-1)) {
				c = mas[NUM-j-1][NUM-i-1];
				mas[NUM-j-1][NUM-i-1] = mas[j][i];
				mas[j][i] = c;
		}
		}
	}
}

void Count_Max_Elem(int mas[][NUM], int count[]) {
	int max;
	for (int i=0;i<NUM;i++) {
		max = 0;
		for (int j=0;j<NUM;j++) {
			if ((j < i) && (j > (NUM-i-1))) {
				max = max > mas[i][j] ? max : mas[i][j]; 
			}
			if ((j > i) && (j < (NUM-i-1))) {
				max = max > mas[i][j] ? max : mas[i][j]; 

			}
		}
		count[i] = max;
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

void PrintMas1 (int mas[]) {
	int i;
	printf("Максимумы:\n");
	for (i = 0; i < NUM; i++) {
		printf(" %02d ", mas[i]);
	}
	putchar('\n');
}


int main() {
	srand(time(NULL));
	int a[NUM][NUM] = {0}, count[NUM] = {0};
	Fill(a);
	PrintMas2(a);
	Swapping_Elem(a);
	PrintMas2(a);
	Count_Max_Elem(a, count);
	PrintMas1(count);
}