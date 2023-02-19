#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node {
    char *info;
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
    rk = strlen(start->info);


    while(start != NULL){
        if (Condition(rk, strlen(start->info), flag) == 1) {
            rk = strlen(start->info);
            *current = start;
            *prevc = prev;
        }
        prev = start;
        start = start->next;
    }
}

int SwapMinMax(node ** start) {
    node *tmp, *prev_tmp, *max, *max_prev, *min, *min_prev;
    Find(*start, &max_prev, &max, 0);
    Find(*start, &min_prev, &min, 1);
    printf("======\n"); // 1 - min 0 - max
    printf("maxlen = %lx\n", strlen(max->info));
    printf("minlen = %lx\n", strlen(min->info));
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


int Add(node ** start, char info[]) {
    node * new, * cur;

    new = malloc(sizeof(node));
    if (new == NULL) {
        exit(2);
    }
    new->info = malloc(sizeof(node)*strlen(info));
    if (new->info == NULL) {
       exit(3); 
    }
    strcpy(new->info, info);
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

node * ReadFromStd() {
    node * start = NULL;
    char buff[128], c;
    int i = 0;

    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            buff[i++] =  c;
            
        }
        else {
            if (i != 0) {
                buff[i]='\0';
                Add(&start, buff);
                i = 0;
            }
        }
    }
    return start;
}

void Read(node * start) {
    while (start != NULL) {
        printf("%s\n", start->info);
        start = start->next;
    }
}


void FreeList(node * start) {
    node * cur;
    char * tmp;
    while (start != NULL) {
        cur = start;
        tmp = start->info;
        start = start->next;
        free(cur);
        free(tmp);
    }
}

void WriteToFile(node * start, FILE * file) {

    while (start != NULL) {
        fprintf(file, "%s\n", start->info);
        start = start->next;
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
        if ((file = fopen(argv[1], "w")) == NULL) {
            printf("file error\n");
            exit(12);
        }
        else {
            printf("success\n");
        }
    }

    start = ReadFromStd();
    

    if (start == NULL) { 
        printf("list is empty\n");
        exit(0);
    }
    
    Read(start);
    SwapMinMax(&start);
    Read(start);
    WriteToFile(start, file);
    FreeList(start);

    fclose(file);
}