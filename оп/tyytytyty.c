

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
	char mas[] = "(){}[]!@#$%^6:;'*&?><~+=_", *uk;
	uk = mas;
	printf("%c\n", *uk);
	while (*uk != '\0') {
		printf("%c\n", *uk);
		uk++;
	}
}