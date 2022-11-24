#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node {
    char *info;
    struct node *next;
};

struct node * Add(struct node *current, char * info) {
    struct node *new;
    char *new_content;
    new = malloc(sizeof(struct node));
    if (new != NULL) {
        new_content = malloc(sizeof(char) *strlen(info));
        if (new_content != 0) {
            strcpy(new_content, info);
            new->info = new_content;
            new->next = current;
            return new;
        }
    }
    printf("Ошибка выделения памяти: 1\n");
    exit(1);  
}

struct node * Delete(struct node *current){
    struct node *previous;
    previous = current->next;
    free(current);
    return previous;
}

void Read(struct node * start) {
    printf("Вывод: \n");
    while (start->next != NULL) {
        printf("%s ", start->info);
        start = Delete(start);
    }
    putchar('\n');
}

int main() {
    struct node *start;
    start = malloc(sizeof(struct node));
    start->info = "start";
    start->next = NULL;
    char buff[40], c;
    int i;

    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            buff[i++] = c;
        }
        else {
            buff[i]='\0';
            start = Add(start, buff);
            i = 0;
        }
    }
    
    Read(start);
}

