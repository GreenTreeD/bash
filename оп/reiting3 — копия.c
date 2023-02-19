#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node {
    int num;
    struct node * next;

} node;

int Condition(int first, int second, int flag) {
    if (flag == 1) {
        return ((first < second) ? 0 : 1);
    }
    else {
        return ((first > second) ? 0 : 1);
    }
}


void Find(node * start, node ** prevc, node ** current, int flag) {
    node * prev = NULL;
    int rk;
    rk = start->num;


    while(start != NULL){
        if (Condition(rk, start->num, flag) == 1) {
            rk = start->num;
            *current = start;
            *prevc = prev;
        }
       //printf("%p %p\n", prev, start);
        prev = start;
        start = start->next;
    }
}

int SwapMinMax(node ** start) {
    node *tmp, *prev_tmp, *max, *max_prev, *min, *min_prev;
    Find(*start, &max_prev, &max, 0);
    Find(*start, &min_prev, &min, 1);
    printf("======\n"); // 1 - min 0 - max
    printf("max = %d\n", max->num);
    printf("mix = %d\n", min->num);
    printf("======\n");

    if ( max_prev == NULL) {
        *start = min;
        min_prev->next = max;
    }

    if ( min_prev == NULL) {
        *start = max;
        max_prev->next = min;
    }
    else {
        max_prev->next = min;
        min_prev->next = max;

    }
    tmp = max->next;
    max->next = min->next;
    min->next = tmp;
   
}


int Add(node ** start, int info) {
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
        return 0;
    }

    *start = new;
    return 0;
}

node * ReadFromFile(FILE * file) {
    node * start = NULL;
    char buff[40], c;
    int i = 0, flag = 0;

    while ((c = fgetc(file)) != EOF) {
        if (!isspace(c)) {
            if(!isdigit(c) && c != '-') {
                flag = 1;
            }
            buff[i++] = c; 
        }
        else {
            if (i != 0) {
                buff[i]='\0';
                if (flag != 1) {
                    Add(&start, atoi(buff));
                }
                i = 0;
                flag = 0;
            }
        }
    }
    return start;
}

void Read(node * start) {
    while (start != NULL) {
        printf("%d \n", start->num);
        start = start->next;
    }
}


void FreeList(node * start) {
    node * cur;
    while (start != NULL) {
        cur = start;
        start = start->next;
        free(cur);
    }
}


int main(int argc, char * argv[]) {
    node * start = NULL;
    FILE * file;

    if (argc < 2) {
        printf("insufficient argument\n");
        exit(13);
    }
    else {
        if ((file = fopen(argv[1], "r")) == NULL) {
            printf("file error\n");
            exit(12);
        }
        else {
            printf("success\n");
        }
    }
    start = ReadFromFile(file);
    fclose(file);

    if (start == NULL) { 
        printf("list is empty\n");
        exit(0);
    }
    
    Read(start);
    SwapMinMax(&start);
    Read(start);
    FreeList(start);
}