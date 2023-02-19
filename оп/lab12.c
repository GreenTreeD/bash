#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node {
    char *info;
    int num;
    struct node *next;
} node;

int Add( node ** start, char * info) {
    node * new, * current = *start;

    if (current == NULL) {
        new = malloc(sizeof(node));
        if (new == NULL) {
            exit(13);
        }
        new->info = malloc(strlen(info)*sizeof(char));
        if (new->info == NULL) {
            exit(14);
        }
        strcpy(new->info, info);
        new->num = 1;
        new->next = NULL;

        *start = new;
        return 0;
    }
    while (current->next != NULL) {
        if (!strcmp(current->info, info)) {
            current->num+=1;
            return 0;
        }
        current = current->next;
    }
    if (!strcmp(current->info, info)) {
            current->num+=1;
            return 0;
        }

    new = malloc(sizeof(node));
    if (new == NULL) {
        exit(3);
    }
    new->info = malloc(strlen(info)*sizeof(char));
    if (new->info == NULL) {
        exit(4);
    }
    current->next = new;
    strcpy(new->info, info);
    new->num = 1;
    new->next = NULL;
    
}

int Delete(node *current){
    node *previous;
    if (current->next != NULL) {
        previous = current->next;
        free(current);
        return 0;
    }    
}

void Read(node * start) {
    node * current;
    printf("Вывод: \n");
    while (start!= NULL) {
        printf("%s %d \n", start->info, start->num);
        current = start;
        start = start->next;
        free(current->info);
        free(current);
    }
}

void Write(node * start, FILE * file) {
    node * current;
    while (start!= NULL) {
        fprintf(file, "%s %d \n", start->info, start->num);
        current = start;
        start = start->next;
        free(current->info);
        free(current);
    }
}



int main(int argc, char * argv[] ) {
    node *start;
    char buff[40], c;
    int i = 0;
    start = NULL;
    FILE * file;
    
    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            buff[i++] = c;
        }
        else {
            if (i != 0) {
            buff[i]='\0';
            Add(&start, buff);
            i = 0;}
        }
    }
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
    
    Write(start, file);
    fclose(file);
}

