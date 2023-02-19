


 #include <stdio.h>
 #include <stdlib.h>


 #define SIZE 1024

 void out_ptr(char *p_mas)
 {
 	char *c_ptr;
 	int j;
 		//передаём начальный элемент массива ссылкок
 	c_ptr = p_mas;
 	j = sizeof(char);	//сдвиг на символ
 	while (*c_ptr != '\0')
 	{
 		putchar(*c_ptr);
 		c_ptr += j;
 	}
 	free(p_mas);
 	putchar('\n');
 }

 char* add_to_buff(char* mas, int i)
 {
 	char* ptr = (char *) malloc(sizeof(char) * (i+1));
 	char* ptr_cur = ptr;

 	while (*mas != '\0') {
 		*ptr = *mas;
 		putchar(*mas);
 		mas += sizeof(char);
 		ptr += sizeof(char);
 	}

 	return ptr_cur;
 }

 void vvod_out(char *p_mas[])
 {
 	char c,*ptr/*save_ptr*/ /*p_mas[SIZE]*/;
 	int i = sizeof(char), j = 0,z = 0;
 	ptr = (char *) malloc(sizeof(char) * SIZE);
 	save_ptr = ptr;


 	while ((c = getchar()) != EOF) //до конца файл ввод
 	{
 		if (c == '\n') 
 		{
 			ptr[j] = '\0';
 			p_mas[z++] = add_to_buff(ptr,j);
 			printf("Кол-во строк: %i\n", z);
 			j = 0;
 		}
 		else
 		{
 			if (c != ' ' && c != '\t')
 			{
 				ptr[j++] = c;
 			}
 		}
 	}
 }

 int main()
 {
 	int i;
 	char* p_mas[SIZE] = { 0 }, * buff;
	
 	vvod_out(p_mas);

 	for (i = 0; i < SIZE - 1; i++) 
 	{
 		if((p_mas[i]) != 0) out_ptr(p_mas[i]);
 	}

 }