#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

static int k=1;

typedef struct s{
int num;
struct s *next;
}comp;

FILE int k, char *a[
{
FILE *f;

if (k != 2)
{
printf("Неккоректный ввод файла\n");
exit(1);
}

f = fopen(a[1], "r"); //открытие файла
if (f==NULL)
{
printf("Open failed\n");
exit(2);
}

return f;
}

comp * add(int n)
{
comp * q;

if ((q = malloc(sizeof(comp))) == NULL) //вывеляем память под узел
{
printf("Не хватает памяти\n");
exit(1);
}

q->num = n; //заполняем узел
q->next = NULL;

return q;
}

comp * zanos_v_spis(comp * spis, int number, comp *last)
{
if (spis == NULL) //первый блок списка
{
spis = add(number);
k++;
return spis;
}
else
{
if (k++ % 2 == 0) //добавление новых цифр
last->next=add(number*2);
else
last->next=add(number);
return last->next;
}
}

int preobraz_slovo_v_chislo(char slovo[], int len)
{
int j, sign, number=0;

if (slovo[0] == '-') //определяем знак
{ j = 1; sign = -1; }
else
{ j = 0; sign = 1; }

for (j; j<len; j++) //формируем число
number = (slovo[j] & 0x0F) + number*10;
number = sign*number;

return number;
}

void vivod(comp *head)
{
comp *f;
int i=1;

f = head;

while (f != NULL)
{
printf("%d\n", f->num);
f = f->next;
}
}

int main(int argc, char *argv[])
{
FILE *fp;
char c;
char chifri[256];
int i=0, flag=0, j, number=0, sign;
comp *last=NULL, *spis=NULL;

fp = openf(argc, argv); //открытие файла

do //считываем посимвольно и составляем слова
{
c = fgetc(fp);
if (isspace(c) || c == EOF)
{
if (i != 0 && flag == 0)
{
chifri[i]='\0';

number = preobraz_slovo_v_chislo(chifri, i);
last = zanos_v_spis(spis, number, last);
if (spis == NULL)
spis = last;
/***printf("%d\n", number);
printf("%d\n", last->num);
printf("%p\n", spis);***/
number = 0;
}
i = 0;
flag = 0;
}
else
if (isdigit(c))
chifri[i++]=c;
else
if (c == '-' && i == 0)
chifri[i++]=c;
else
flag = 1;
}
while(c != EOF);

vivod(spis);
}