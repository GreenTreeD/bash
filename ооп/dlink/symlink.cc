// Случайная перестановка строки символов
#include  <stdio.h>
#include  <stdlib.h>
#include  "dlink.h"

// Класс элемент списка символов, производный от базового
// класса двусвязного списка
class SymLink : public Dlink {
private:
    unsigned char sym; // код символа
public:
    // инициализации  кода  символа  и  базовых  адресов
    SymLink(unsigned char c) : Dlink(), sym(c) {};
    // перегрузка  базового метода incr
    SymLink* incr() {return((SymLink*) Dlink::incr());};
    // перегрузка  базового метода decr
    SymLink* decr() {return((SymLink*) Dlink::decr());};
    SymLink* seek(int); // смещение указателя на заданное число элементов списка
    int print();	// печать элементов списка
}; // SymLink
// метод сдвига к началу или к концу списка на n элементов
// в зависимости  от  знака  аргумента
SymLink* SymLink::seek(int n) {
    if(n > 0) // сдвиг  к  хвосту  списка  от  текущего  адреса  базовы м методом  totail
        return((SymLink* ) Dlink::totail(n));
    if(n < 0) // сдвиг  к  началу  списка  от  текущего  адреса
        return((SymLink* ) Dlink::tohead(abs(n))); // базовым  методом  tohead
    return(this);   // нулевой сдвиг
} // Symlink::seek
// Печать  и  подсчет  элементов  от начала до конца списка
int SymLink::print() {
    SymLink* p = this; // текущий адрес символа списка
    SymLink* q; // адрес следующего символа списка
    int n= 0; // счетчик символов
    while(p != NULL){ // цикл  просмотра  до  конца списка
        putchar(p->sym); // печать текущего символа списка
        q = p->incr();// получить адрес следующего символа списка
        p = q; // перейти к следующему символу списка
        n++;// увеличить счетчик числа символов
    }// while
    printf ("%d\n", n);
    return(n); // возврат числа напечатанных символов
} // SymLink::print
// основная функция
int main(int argc, char* argv[]) {
    unsigned seed =0; // зерно  псевдо-случайной  последовательности
    int count = 0; // счетчик  случайных  перестановок  символов  списка
    int length; // длина списка символов
    int ch; // код входного символа
    unsigned pos; // смещение  символа  от  начала  списка
    int side; // индекс  сторожевого  символа  списка
    SymLink* watch[2]; // адреса  сторожевых  символов  в  начале  и  конце  списка
    SymLink* head; // адрес  начала  списка  символов
    SymLink* tail; // адрес  конца  списка  символов
    SymLink* p;
    SymLink* q; // текущие  адреса  символов  списка
    // массив  адресов  методов  вставки  символов
    Dlink* (Dlink::* insert[])(Dlink*) = {&Dlink::after, &Dlink::before};
    if(argc >1) // получить  зерно  случайной  последовательности  символов
        seed = atoi(argv[1]); // из аргумента командной строки вызова программы
    // распределить сторожевые символы в начале и конце списка
    watch[0] = head = new  SymLink('\n');  // адресовать  LF  в  начале  списка
    watch[1] = tail = new  SymLink('\n'); // адресовать  LF  в  конце  списка
    tail ->before(head); // связка 2 сторожевых символов в пустой список
    // распределить список символов из строки стандартного ввода
    while((ch = getchar()) != '\n') { // ввод символа до LF
        q = new SymLink(ch); // распределить элемент списка
        tail->before(q); //вставить символ в конец списка перед концевым сторожем
    } // while
    // вывод исходного списка символов и подсчет его длины
    if((length = head->print ( ) - 1) < 2)
        count = length;
    printf("len=%d\n", length);
    
    // блокировать обработку пустого списка
    // случайное перемешивание символов в списке
    srand(seed); // установить зерно псевдо-случайной последовательности
    while(count < length) { // цикл перемешивания
        side = rand() % 2; // случайный выбор начала или конца списка
        while((pos = rand() % length) == 0); // случайный выбор символа в списке
        printf("%*c\n", pos, '^'); // индикация выбора символа
        q = head->seek(pos); // адресация выбранного символа
        q->excluse(); // исключить выбранный символ из списка
        (watch[side]->*insert[side])(q); // вставить его в начало или конец списка
        head->print();// печать списка после перестановки символа
        count++; // увеличить счетчик перестановок символов
    } // while
    // удалить список символов
    p = tail;// адресовать конец списка
    while(p != NULL) { // цикл удаления списка от конца к началу
        q = p->decr(); // фиксировать адрес предыдущего символа списка
        p->excluse(); // исключить символ списка по текущему адресу
        delete p; // освободить память исключенного символа списка
        p = q; // адресовать предыдущий символ списка
    } // while
    return(length+1);// завершение программы возвратом длины списка
} // main
