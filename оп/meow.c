#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



typedef struct node {
    int num;
    struct node * next;

} node;


void Swap(node * first, node * second) {
    int tmp;
    tmp = first->num;
    first->num = second->num;
    second->num = tmp;
}


int iswrong(char c) {
    char mas[] = "(){}[]!@#$%^:;'*&?><~+=_", *uk;

    if (isalpha(c)) {
        return 1;
    }
    while (*uk != '\0') {
        if (c == *uk) {
            return 1;
        }
        uk++;
    }
    return 0;
}

node * Add(node ** start, int info) {
	node * new, * cur;

	new = malloc(sizeof(node));
    if (new == NULL) {
        exit(2);
    }
    new->num = info;
    new->next = NULL;

	if ((*start)!= NULL) {
		cur = * start;
		while(cur->next != NULL) {
			cur = cur->next;
		}
		cur->next = new;
		return new;
	}

    *start = new;
    return new;
}

node * ReadFromFile(FILE * file) {
    node * start = NULL;
    char buff[40], c;
    int i = 0, flag = 0, tmp;

    node *max, * min;

    while ((c = fgetc(file)) != EOF) {
    	if (!isspace(c)) {
            if(iswrong(c)) {
                flag = 1;
            }
            buff[i++] = c; 
        }
        else {
            if (i != 0) {
                buff[i]='\0';
                if (flag != 1) {
                	tmp = atoi(buff);
                    Add(&start, tmp);
                    printf("%s\n", buff);

                    if (tmp > max->num) {
                    	max = Add(&start, tmp);

                    }
                    else {
                    	if (tmp < min->num){
                    		min = Add(&start, tmp);

                    	}
                    	else {
                    		Add(&start, tmp);
                    	}
                    }

                }
                i = 0;
                flag = 0;
            }
        }
    }

    printf("======\n");
    printf("min = %d\n", min->num);
    printf("max = %d\n", max->num);
    printf("======\n");

    Swap(max, min);

    return start;
}


void FreeList(node * start) {
    node * cur;
    while (start != NULL) {
    	printf("%d \n", start->num);
        cur = start;
        start = start->next;
        free(cur);
    }
}


int main(char argc[], char * argv[]) {
    node * start;
    FILE * file;


     if ((file = fopen(argv[1], "r")) == NULL)
    {
        printf("Не удалось открыть файл");
        exit(5);
    }
    else {
        printf("Файл открыт\n");
    }

    start = ReadFromFile(file);
    fclose(file);
    FreeList(start);

}