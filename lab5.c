#include <stdio.h>
					// функция ввода и проверки числа: числа в диапазоне от 1 до 100, возвращает введённый возраст
int input() {
        int n;
        int f, e;
        n = -1;
	printf("Введите возраст: \n");
        f = (scanf("%d", &n));
        while (!(((n > 0) && (n < 101)) && f)) {
        	printf("Ошибка, повторите ввод: \n");
			while (getchar() != '\n'); 
			f = (scanf("%d", &n));
        }     
	return n;
}
					// получение нужного слова для описания возраста, принимает число - возраст, возвращает строку - слово
const char* ret(int age) {
	int d = age % 10;
	d = ((age> 10)&& (age < 20)) ? 5 : d;
	if ((d == 0) || (d>4)) {
		return "лет";
	}
	else {
		switch (d) {
			case 1: return "год"; break;
			default: return "года"; break;
		}
	}
}
				// единая функция для вывода обеих строчек, при аргументе 1 - совершеннолетие, аргумент 2 - пенсия
void output(int age, int choice) {
	const char* word1 = (choice == 1) ? "совершеннолетний" : "пенсионер";
	const char* word2 = (choice == 1) ? "совершеннолетия" : "пенсии";
	int ch = (choice == 1) ? 18 : 60;
	int d = (age < ch) ? 1 : 2;

	if (age == ch) {
		printf("Вы %s\n", word1);
	}
	else {
		switch (d) {
			case 1: printf("Вам %d %s до %s\n", ch-age, ret(ch-age), word2); break;
			case 2: printf("Вы уже %d %s %s\n", age-ch, ret(age-ch), word1); break;
		}
	}
}


int main () {
	int age, d;
	
	age = input();
	const char* nums = ret(age);
	printf("Вам %d %s\n", age, nums);
	output(age, 1);
	output(age,2);
}