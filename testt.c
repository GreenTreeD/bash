#include <stdio.h>
#include <math.h>
#define RATIO 1.6180339887498949025257388711906969547271728515625


double fib(int n)
{
	if (n <= 1)
	{
		return (double)n;
	}
	return fib(n - 1) + fib(n - 2);
}

double input(double* prec) {

	printf("Введите точность");
}

void golden_ratio(double* x)
{
	int n = 1;
	double fib0, fib1, fib2;
	fib0 = fib(n);
	fib1 = fib(n-1);
	fib2 = fib(n-2);
	while(fabs((fib0/fib1) - (fib1/fib2))>=0.0001)
	{
		n++;
		fib2 = fib1;
		fib1 = fib0;
		fib0 = fibonacci(n);
	}
	printf("%d\n", n);
	*x = fib0 / fib1;
}



int main () {
	double PREC, ratio;
	int i;
	i = 1;
	
	golden_ratio(&ratio);
	printf("%.50lf\n", ratio);
	printf("%.50lf\n", (1+pow(5, 0.5))/2);
	
		
	
	
	
}

