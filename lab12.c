#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node {
    char *info;
    int num;
    struct node *next;
} node;

int Add(struct node *current, char * info) {
    node * new;
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

int Delete(struct node *current){
    node *previous;
    if (current->next != NULL) {
        previous = current->next;
        free(current);
        return 0;
    }    
}

void Read(struct node * start) {
    printf("Вывод: \n");
    while (start!= NULL) {
        printf("%s %d \n", start->info, start->num);
        start = start->next;
    }
}

node * Init(char * info) {
    node * head;

    head = malloc(sizeof(node));
    if (head == NULL) {
        exit(1);
    }
    head->info = malloc(strlen(info)*sizeof(char));
    if (head->info == NULL) {
        exit(2);
    }
    strcpy(head->info, info);
    head->num = 1;
    head->next = NULL;
    return head;
}


int main() {
    node *start;
    char buff[40], c;
    int i = 0;
    start = NULL;

    c = getchar();
    while (!isspace(c) && c != EOF) {
        buff[i++] = c;
        c = getchar();
    }
    if (i != 0) {
        buff[i] = '\0';
        start = Init(buff);
        i = 0;
    }
    
    while (c != EOF) {
        if (isalpha(c)) {
            buff[i++] = c;
        }
        else {
            if (i != 0) {
            buff[i]='\0';
            Add(start, buff);
            i = 0;}
        }
    c = getchar();
    }
    Read(start);
}

