#include <stdio.h>
#include <math.h>
#define RATIO 1.6180339887498949025257388711906969547271728515625

					// функция для вычисление числа ряда Фибоначчи
double fib(int n)
{
	if (n <= 1)
	{
		return (double)n;
	}
	return fib(n - 1) + fib(n - 2);
}

					// функция ввода и проверки точности
double input() {
	double n;

	printf("Введите точность: \n");
	while(scanf("%lf", &n) != 1) {
		printf("Ошибка, повторите ввод: \n");
		while (getchar() != '\n');
       
	}
	return n;
}

					// функция для вычисления золотого сечения при заданной точности, возвращает номер числа ряда и значение числа
void golden_ratio(double* x, double prec)
{
	int n = 1;
	double fib0, fib1, fib2;
	fib0 = fib(n);
	fib1 = fib(n-1);
	fib2 = fib(n-2);
	while(fabs((fib0/fib1) - (fib1/fib2))>= prec)
	{
		n++;
		fib2 = fib1;
		fib1 = fib0;
		fib0 = fib(n);
	}
	printf("Номер числа ряда Фибоначчи: %d\n", n);
	*x = fib0 / fib1;
}



int main () {
	double prec, ratio;

	prec = input();
	golden_ratio(&ratio, prec);
	printf("Число золотого сечения: %.50lf\n", ratio);
	printf("Абсолютная погрешность: %.50lf\n", fabs(RATIO-ratio));
	printf("Относительная погрешность: %.10lf\n", (ratio/RATIO)*100);
}

