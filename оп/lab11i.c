#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node {
    char *info;
    int num;
    struct node *next;
};

int Add(struct node *current, char * info) {
	struct node * new;
	char * new_content = malloc(strlen(info)*sizeof(char));
	while(current->next != NULL) {
		if (!strcmp(current->info, info)) {
			current->num+=1;
			return 0;
		}
		current = current->next;
	}
	new = malloc(sizeof(struct node));
	strcpy(new_content, info);
	current->info = new_content;
	new->num = 1;
	new->next = NULL;
	current->next = new;
}

void Read(struct node * start) {
	struct node * cur;
	while (start->next != NULL) {
		printf("%s %d\n", start->info, start->num);
		cur = start;
		start = start->next;
		free(cur);
	}
	printf("===========\n");
}

int main() {
    struct node *start;
    start = malloc(sizeof(struct node));
    start->next = NULL;
    start->num = 1;

    char buff[40], c;
    int i;
    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\n') {
            if (isalpha(c)) {
                buff[i++] = c;
            }
        }
        else {
            if (i != 0) {
            buff[i]='\0';
            Add(start, buff);
            //printf("###%s\n", buff );
            i = 0;}
        }
    }
    printf("------------\n");
    Read(start);

}

