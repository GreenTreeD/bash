#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PREC 0.0001
#define ANSW 3.00162937099076


double Expression(double x) {
	return (cos(0.5*x) - pow(x,2) + 10);}

void Solution() {
	double start = 0.0, end = 8.0, mid, exp_answ;
	mid = (start+end) / 2;
	exp_answ = Expression(mid);
	while(fabs(ANSW-exp_answ) > PREC) {
		if (exp_answ > ANSW) { start = mid;}
		else { end = mid; }
	mid = (start+end) / 2;
	exp_answ = Expression(mid); }
	printf("Ответ: %lf\n", exp_answ);
	printf("Абсолютная погрешность: %lf\n", fabs(exp_answ-ANSW));
	printf("Относительная погрешность: %lf\n", fabs(exp_answ-ANSW)/ANSW); }

void Table() {
	double start = 0.0, end = 8.0, range = (end-start)/19;
	int i;
	printf("-----------------------\n");
	for (i = 0; i <= 19; i++) {
		printf("| %8.3lf | %8.3lf |\n", start,Expression(start));
		start+=range;}
	printf("-----------------------\n");}

int main() 
{	printf("Точность: %g\n", PREC);
	Solution();
	Table();}