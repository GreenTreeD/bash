#include <stdio.h>

int main()
{
	int a1, q;
	printf("введите значения шага и нач. значения через запятую\n");
	while (scanf("%d,%d",&q,&a1)!=2)
	{
		while(getchar() != '\n');
		printf("ОШИБКА!!!");
	}

	for (int i=0;i<12;i++)
	{
		
		printf ("%d. %d \n", i+1, a1);
		a1+=q;//a1 = a1 +q
	}
}


