#include <stdio.h>

int main()
{
	float x,y;
	printf("введите координаты точки\n");
	while (scanf("%f %f",&x,&y)!=2)
	{
		while(getchar() != '\n');
		printf("ОШИБКА!!!");
	}

	if (x<0)
	{
		printf("не подходит!\n");
		return (0);
	}
	//printf("%f\n", x*x+y*y );
	if ((x*x+y*y<=16)&&(x*x+y*y>=4))
	{
		printf("подходит!\n");
		return (0);
	}
	printf("не подходит!\n");
		return (0);

}