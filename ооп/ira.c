#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct letter {
int table[5][5];
} letter;

typedef struct number {
	int count;
	letter ** t;
} number;



letter * CreateLetter(int);
void PrintLetter(letter *);
void PrintNum(letter **, int);
number * CreateNum (char *);


number * CreateNum (char * num) {
	number * temp;
	int n = strlen(num);
	letter ** templist;
	int i = 0;


	temp = (number *) malloc(sizeof(number));
	if (temp == NULL) {
		printf("Malloc error: 1\n");
		exit(3);
	}
	templist = (letter **) calloc(n,sizeof(letter*));
	if (templist == NULL) {
		printf("Calloc error: 1\n");
		exit(3);
	}
	temp->count = n;

	for(i = 0; i < n; i++) {
		templist[i] = (letter *) malloc(sizeof(letter));
		if (templist[i] == NULL) {
			printf("Malloc error: 2\n");
			exit(3);
		}
		templist[i] = CreateLetter((int)(num[i]-'0'));
	}
	temp->t = templist;

	return temp;
}

letter * CreateLetter(int n) {
	letter * temp;
	temp = (letter *) malloc(sizeof(letter));
	if (temp == NULL) {
		printf("Malloc error: 3\n");
		exit(4);
	}
	int nums[10][5][5] = {
		{
			{0,1,1,1,0}, // 0
			{1,0,0,1,1},
			{1,0,1,0,1},
			{1,1,0,0,1},
			{0,1,1,1,0}
		}, 
		{
			{0,0,1,0,0}, //1
			{0,1,1,0,0},
			{0,0,1,0,0},
			{0,0,1,0,0},
			{1,1,1,1,1}
		}, 
		{
			{1,1,1,1,0}, //2
			{0,0,0,0,1},
			{0,1,1,1,0},
			{1,0,0,0,0},
			{1,1,1,1,1}
		},
		{
			{0,1,1,1,0}, //3
			{1,0,0,0,1},
			{0,0,1,1,0},
			{1,0,0,0,1},
			{0,1,1,1,0}
		},
		{
			{0,0,1,1,0}, //4
			{0,1,0,1,0},
			{1,0,0,1,0},
			{1,1,1,1,1},
			{0,0,0,1,0}
		},
		{
			{1,1,1,1,1}, //5
			{1,0,0,0,0},
			{1,1,1,1,0},
			{0,0,0,0,1},
			{1,1,1,1,0}
		},
		{
			{0,1,1,1,1}, //6
			{1,0,0,0,0},
			{1,1,1,1,0},
			{1,0,0,0,1},
			{0,1,1,1,0}
		},
		{
			{1,1,1,1,1}, //7
			{0,0,0,0,1},
			{0,0,0,1,0},
			{0,0,1,0,0},
			{0,0,1,0,0}
		},
		{
			{0,1,1,1,0}, //8
			{1,0,0,0,1},
			{0,1,1,1,0},
			{1,0,0,0,1},
			{0,1,1,1,0}
		},
		{
			{0,1,1,1,0}, //9
			{1,0,0,0,1},
			{0,1,1,1,1},
			{0,0,0,0,1},
			{0,1,1,1,0},
		}
	};
	for (int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) { 
			temp->table[i][j] = nums[n][i][j];
		}
	}
	return temp;
}

void PrintLetter(letter * A) {
	for (int i = 0; i < 5; i++) {
		for(int j = 0; j < 5;j++) {
			if (A->table[i][j]) {putchar('#');}
			else {putchar(' ');}
		}
		putchar('\n');
	}
}

void PrintNum(number * B) {
	letter ** A = B->t;
	int col = B->count;
	putchar('\n');
	for (int j = 0; j < 5; j++) {
		putchar(' ');	
		for (int i = 0; i < col; i++) {
			for (int k = 0; k < 5; k++) {
				if (A[i]->table[j][k]) {
					putchar('@');
				}
				else{putchar(' ');}
			}
			putchar(' ');		
		}
		putchar('\n');
	}
	putchar('\n');

}

int main(int argc, char ** argv) {
	number * A = NULL;
	A = CreateNum(argv[1]);
	PrintNum(A);


	/*letter *A[3];
	A[0] = (letter *) malloc(sizeof(letter));
	A[1] = (letter *) malloc(sizeof(letter));
	A[2] = (letter *) malloc(sizeof(letter));
	A[0] = CreateLetter(1);
	A[1] = CreateLetter(9);
	A[2] = CreateLetter(0);
	PrintNum(A, 3);*/

}