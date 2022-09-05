
#include <stdio.h>
#include <time.h>

int main () {
	int t,hour,min,sec;
	t = time(NULL);
	hour = (t / 3600)%24;
	t = t%3600;
	sec = t % 60;
	min = t / 60;
	printf("Время GTM+0: ");
	printf("%d:%d:%d\n", hour,min,sec);

 }