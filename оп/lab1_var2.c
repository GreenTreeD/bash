#include <stdio.h>


int main () {
    int a,b,S;

    printf("Введите первую сторону: ");
    while (scanf("%d",&a) != 1) 
    {
        while (getchar() != '\n');
        printf("Одна ошибка и вы ошиблись");
    }
    printf("Введите вторую сторону: ");
    while (scanf("%d",&b) != 1) 
    {
        while (getchar() != '\n');
        printf("Одна ошибка и вы ошиблись");
    }
    S = a * b;
    printf("Площадь: %d\n", S);

}
