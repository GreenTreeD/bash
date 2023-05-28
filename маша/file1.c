#include <stdio.h>
#include <stdlib.h>

int main(){
	int a;
	printf("Введите число\n");
	if (scanf("%d", &a) == 0) {
		printf("вы чё делаете а....\n");
		exit(4);
	}
	for (int i=1; i<=a; i++){
		printf("%d\n",i);
	}
}