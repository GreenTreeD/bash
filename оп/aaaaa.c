#include <stdio.h>
#include <stdlib.h>


#define MAS(x) x
#define MAd(x) #x



int main() {
	struct ty {
		int a;
		int b;
	}pyyyy;

	struct ty tyyyy;
	printf(MAd(MAS(12+7)));
	
	printf("%d\n", tyyyy);
	printf("%d\n", pyyyy);
}
