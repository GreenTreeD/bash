#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main() {
	int mas[] = {1,2,3,4,5,6,7,8,9,10,56,23,76,12,34,-12,456,23};
	int pr, cur = mas[0];
	int max = cur, prmax;
	for (int i = 1; i < (sizeof(mas)/sizeof(int)); i++) {
		pr = cur;
		cur = mas[i];
		if (mas[i] > max) {
			max = cur;
			prmax = pr;
		}
		printf("%d %d\n", pr, cur);
	}

printf("========%d %d\n", prmax, max);
}