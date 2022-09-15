
#include <stdio.h>
#include <complex.h>
#include <math.h>
/* Поключение модулей */

int main () {
	double a,b,c,d,x1,x2;
	double complex cx1, cx2, d1;

	a = 1.2;
	
	do {
		if (a == 0) {
			printf("Ошибка! Введите коэф.заново. Повторите попытку.\n");
		}

	printf("Введите коэф. а: \n");
	scanf("%lf",&a);
	printf("Введите коэф. b: \n");
	scanf("%lf",&b);
	printf("Введите коэф. c: \n");
	scanf("%lf",&c);
	}

	while (a == 0); 

	d = b*b - 4*a*c;

	if (d == 0) {
		x1 = (-b)/(2*a);
			printf("%.4f",x1);
	}
	else {
		if (d > 0) {

			x1 = (-b + sqrtf(d))/(2*a);
			x2 = (-b - sqrtf(d))/(2*a);
			printf("%.3f %.3f \n",x1,x2);

		}
		else {
			d1 = csqrtf(d);
			cx1 = (-b + d1)/(2*a);
			cx2 = (-b - d1)/(2*a);
			printf("%.3f%+.3fi\n", creal(cx1),cimag(cx1));
			printf("%.3f%+.3fi\n", creal(cx2),cimag(cx2));
		}

	}

 }
