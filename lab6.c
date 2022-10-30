#include <stdio.h>
#include <string.h>


int vvod1 (double *num) {
 char tr;
 while ((tr = scanf("%lf", &*num)) != 1) {
    printf("  Введите число (с .):    ");
    while(getchar() != '\n');
 }
} 
 
int vvod2 (int *num) {
 char tr;
 while ((tr = scanf("%d", &*num)) != 1 || *num < 2 || *num > 16) {
    if (tr != 1) printf("  Введите число:    ");
    else printf("  Введите число от 2 до 16:    ");
    while(getchar() != '\n');
 }
} 

int perevod1 (int n, int si) {
	 char s[100] = "";
	 int i, ost, c = n, len;

	 while (c > 0) {
	    ost = c % si;
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
	    //printf("%d\n", c);
	    ost = (int)(c/si);
	    c = ost;
	 }

	 printf("\nu%su    %d",s,c);
	 len = strlen(s);
	 printf("\n%s",s);
	 printf("Число в %d-ичной СИ:   \n", si);
	 for(len ; len >= 0; len = len - 1) {
	    printf( "%c", s[len] );
 }
}

int perevod2 (double n, int si) {

}



int main () {
 int si, c, m = 0; 			// система исчсиления,  целая часть, минус
 double num, d;				// само число, дробная часть
 
 
 printf("  Введите переводимое число:   ");
 vvod1(&num);
 
 if (num < 0) {m = 1; num = -num;}
 
 // fflush(stdin);
 printf("  Введите ПСИ (число):   ");
 vvod2(&si);
 
 c = (int)num;
 printf("%d\n", c);
 d = num - c;
 
 perevod1(c, si);
 perevod2(d, si);

 
 }





/*#include <stdio.h>
#include <string.h>
 

 
 
int main() 
{
    char string[] = "string";
    printf("%c\n", string[0]);

    char j[] = "123456789012345";
    int i, k  = strlen(j);
    printf("%s\n",j);
    for (int i = k-1; i >= 0 ; i--) 
    {
       printf("%c\n",j[i]);
    }

}*/