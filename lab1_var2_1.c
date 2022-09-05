#include <stdio.h>


int main () {
    int a,b,S,flag;
    flag = 0;

    printf("Введите первую сторону: ");
    
    while (flag != 1) {
        while (scanf("%d",&a) != 1) 
        {
            while (getchar() != '\n');
            printf("Одна ошибка и вы ошиблись");
            
        }
        if (a< 0) {
            while (getchar() != '\n');
            printf("Одна ошибка и вы ошиблись");
        }
        if (a > 0) {
            flag = 1;
        }
    }
    flag = 0;
    printf("Введите вторую сторону: ");
    while (flag != 1) {
        while (scanf("%d",&b) != 1) 
        {
            while (getchar() != '\n');
            printf("Одна ошибка и вы ошиблись");
            
        }
        if (b < 0) {
            while (getchar() != '\n');
            printf("Одна ошибка и вы ошиблись");
        }
        if (b > 0) {
            flag = 1;
        }
    }
    S = a * b;
    printf("Площадь: %d\n", S);

}
