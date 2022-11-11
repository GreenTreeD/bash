#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NUM 8

void Fill(int mas[][NUM]) {
	//srand(2);
	srand(time(NULL));
	int i,j,c;

	for (i=0;i<NUM;i++) {
		mas[i][i] = 0; // заполнение диагонали нулями
		for (j=0;j<i;j++) {
			c = rand()%(3);
			mas[i][j] = c == 2 ? 3: c;
			mas[j][i] = (2 - c) == 2 ? 3: (2 - c);
		}
	}
}

int Count(int mas[][NUM], int count[]) {
	int i,j,c, maxx; 
	for (i=0;i<NUM;i++) {
		c = 0;
		for (j=0;j<NUM;j++) {
			c+= mas[i][j];			
		}
		count[i] = c;
		maxx = c > maxx ? c : maxx;
	}
	return maxx;
}

void PrintMas2(int mas[][NUM]){
	int i,j;
	putchar('\n');
	printf("   ");
	for (i=0;i<NUM;i++) { printf(" к%02d" , i+1);}
	putchar('\n');	
	for (i=0;i<NUM;i++) {
		printf("к%02d", i+1);
		for (j=0;j<NUM;j++) {
			printf(" %2d ", mas[i][j]);
		}
		putchar('\n');
	}
	putchar('\n');
}

void PrintMas1 (int mas[]) {
	int i;
	printf("%31s", "Команды:");
	for (i = 0; i < NUM; i++) {
		printf(" %02d ", i+1);
	}
	putchar('\n');
	printf("%40s", "Количество баллов:");
	for (i = 0; i < NUM; i++) {
		printf(" %02d ", mas[i]);
	}
	putchar('\n');
}

void CountTeams(int c, int mas[]) {
	int i;
	printf("Команды с максимальным количеством баллов:");
	for (i = 0; i < NUM; i++) {
		if (mas[i] == c) {
		printf(" к%d ", i+1);}
	}
	putchar('\n');
}

int main() {
	int a[NUM][NUM], count[NUM];
	int i,j,c;
	Fill(a);
	PrintMas2(a);
	c = Count(a,count);
	PrintMas1(count);
	printf("Максимальное количество баллов: %d\n", c);
	CountTeams(c, count);

}