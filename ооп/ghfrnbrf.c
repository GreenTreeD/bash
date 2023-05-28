#include <stdio.h>
#include <stdlib.h>


typedef struct triangle {
	int degree;
	int ** table;
	int max;
} triangle;

void Create(triangle **, int);
void Print(triangle);
void Fill(triangle);
void Delete(triangle);

void Create(triangle ** st, int n) {

	*st = NULL;
	triangle * temp;
	int * list;

	temp = (triangle *)malloc(sizeof(triangle));
	if (temp == NULL) {
		printf("Calloc error: 1\n");
		exit(-2);
	}
	temp->table = (int **)calloc(n, sizeof(int*));
	temp->degree = n;
	temp->max = 0;

	if (temp->table == NULL) {
		printf("Calloc error: 2\n");
		exit(-2);
	}

	for (int i = 0; i < n; i++){

		list = (int *)calloc(i+1, sizeof(int));
		if (list == NULL){
			printf("Calloc error: 3\n");
			exit(-2);
		}
		for (int j = 0; j < i; j++){
			list[j] = 0;
		}

		temp->table[i] = list;
	}
	*st = temp;
}

int Count(int n) {
	int i = 0;
	while(n > 0) {
		n /= 10;
		i++;
	}
	return i;
}

void Print(triangle * A) {

	int ** listB = (A->table);
	int * listS = listB[0];
	int m = Count(A->max);

	for (int i = 0; i < A->degree; i++) {
		listS = listB[i];
		for(int j = 0; j <= i; j++){
			printf("%*d ", m, listS[j]);
		}
		putchar('\n');
	}
}

void Delete(triangle ** A) {
	triangle * B = *A;
	int ** listB = (B->table);

	for (int i = 0; i < B->degree; i++) {
		free(listB[i]);
	}
	free(listB);
	free(B);

	*A = NULL;
}

void Fill(triangle * A){
	int ** listB = (A->table);
	int j = 0;
	for (int i = 0; i < A->degree; i++) {
		listB[i][0] = 1;
		for(j = 1; j < i; j++) {
			listB[i][j] = listB[i-1][j] + listB[i-1][j-1];
			A->max = (A->max > listB[i][j]) ? A->max : listB[i][j];
		}
		listB[i][j] = 1;	
	}
}

int main(int argc, char ** argv) {

	triangle * A = NULL;
	int n;

    if (argc < 2) {
        printf("Insufficient arguments\n");
        exit(-1);
    }

    n = atoi(argv[1]);
    if (n <= 0) {
    	printf("Wrong input\n");
        exit(-1);
    }

    if (n > 34) {
    	printf("Sorry this number is too big for me to process :(\n");
    	exit(0);
    }

    Create(&A, n);
    Fill(A);
    Print(A);
    Delete(&A);
}