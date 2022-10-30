#include <stdio.h>
#include <string.h>
 
double vvod1() {
	double n;
	while (!scanf("%lf",&n)) {
		printf("Ошибка, введите число\n");
		while(getchar() != '\n');
	}
	return n;
}

int vvod2() {
	int n, f;
	n = -10;
	while ((f = scanf("%d", &n) == 0) || (n < 1) || (n > 17)) {
		printf("Ошибка, ");
		if ((n < 2)||(n > 16)) {
			printf("введите число от 2 до 16\n");
			n = 4;
		}
		else {
			printf("введите число\n");
		}
    	while(getchar() != '\n');
	}
	return n;
}


void t1(int num, int d) {
	char s[100] = "";
	int ost,i;
	
	while (num > 0) {
		ost = num % d;

		switch (ost) {
		       case 0:  strcat(s, "0"); break;
		       case 1:  strcat(s, "1"); break;
		       case 2:  strcat(s, "2"); break;
		       case 3:  strcat(s, "3"); break;
		       case 4:  strcat(s, "4"); break;
		       case 5:  strcat(s, "5"); break;
		       case 6:  strcat(s, "6"); break;
		       case 7:  strcat(s, "7"); break;
		       case 8:  strcat(s, "8"); break;
		       case 9:  strcat(s, "9"); break;
		       case 10: strcat(s, "A"); break;
		       case 11: strcat(s, "B"); break;
		       case 12: strcat(s, "C"); break;
		       case 13: strcat(s, "D"); break;
		       case 14: strcat(s, "E"); break;
		       case 15: strcat(s, "F"); break;
	    } 
	    num = (int) num/d;
	}
	for(i = strlen(s)-1;i >=0; i--) {
		printf("%c", s[i]);
	}
}

void t2(double num, int d) {
	int i;
	for (i = 0; i <5; i++) {
		num*=d;
		printf("%x",(int) num);
		num = num-(int)num;
	}
}
 
int main() 
{
	double n, dl;
	int d, nn;
	printf("Веведите исходное число: \n");
    n = vvod1();
    printf("Введите систему счисления: \n");
    d = vvod2();

    if (n < 0) {
    	printf("-");
    	n = -n;
    }
    nn = (int) n;
    dl = n - nn;
    
    if (nn == 0) {
		printf("0");
	}
	else {
		t1(nn,d);	
	}
    if (dl == 0) {
    	printf("\n");
    }
    else {
    	printf(".");
    	t2(dl,d);
    	printf("\n");
    }
}