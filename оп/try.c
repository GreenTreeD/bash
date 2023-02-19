#include <stdio.h>
#include <stdlib.h>

int vvod(int* n) {
	printf("Введите число: \n");
	while(scanf("%d", n) != 1) {
		printf("Ошибка, повторите ввод: \n");
		while (getchar() != '\n'); 
	}
}

int summa(int* k, int i) {
	int s = 0, j;
	for (j = 1; j <= i; j++) {
		s+=*k;
		*k+=2;
	}
	return s;
}

int work1(int n, int s, int i, int k) {

	while (abs(n) > s) {
		i+=1;
		s = summa(&k,i);
	}
	printf("Ответ: %d\n",-i);
}

int work2(int n, int s, int i, int k) {

	while (n >= s) {
		i+=1;
		s = summa(&k,i);
	}
	printf("Ответ: %d\n",i-1);

}

int main() {
	int n,i,s,k;
	vvod(&n);
	s = 1;
	i = 0;
	k = 1;
	if ((n >= -1)&&(n<=1)) {
		printf("Ответ: %d\n", n);
	}
	else {
		if (n < 0) {
			work1(n,s,i,k);
		}
		else {
			work2(n,s,i,k);
		}
	}
	
}



