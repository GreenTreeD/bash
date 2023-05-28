#include <cctype>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Alpha{
private:
    unsigned bin[2];
public:
    Alpha();
    Alpha(char*);

    friend ostream & operator << (ostream &, Alpha);
    int operator , (Alpha);
    friend int pop (unsigned);
};

Alpha::Alpha() {
    char str[] = "AEOIU";
    char *s;
    s = str;

    bin[0] = 0;
    bin[1] = 0;

    while (*s) {
        bin[0] |= (1 << (tolower(*s)-'a'));
        s++;
    }
}


Alpha::Alpha(char *s) {
    bin[0] = 0;
    bin[1] = 0;

    while(*s) {
        if (isupper(*s)) {
            bin[0] |= (1 << (tolower(*s)-'a'));
        }
        else {
        bin[1] |= (1 << (tolower(*s)-'a')); 
        }
        s++;
    }
}


int pop(unsigned b){
    int i=0;
    while (b != 0){
        b = b & ( b - 1);
        i++;
    }
    return i;                                             
}


int Alpha::operator , (Alpha y) {
    return pop(bin[0] & y.bin[0]) + pop(bin[1] & y.bin[1]);
}

ostream & operator<< (ostream & out, Alpha x) {
    unsigned a = x.bin[0];
    int c = 0;
    while (a > 0){
        if (a & 1){
            out << (char) toupper('a'+c); 
        }
        a = a >> 1;
        c++;
    }
    c = 0;
    a = x.bin[1];
    while (a > 0){
        if (a & 1){
            out << (char) ('a'+c); 
        }
        a = a >> 1;
        c++;
    }
    return out;
}


int main (int argc, char* argv[])
{

    if (argc != 2) {
        cout << "Usage: <string1>" << endl;
        return -1;
    }
    Alpha a;
    Alpha b(argv[1]);
    int s = (a,b);
    cout << "Подмножество букв из введённой строки: " << b << endl;
    cout << "Строка по умолчанию: " << a << endl;
    cout << "(a,b) = " << s << endl;
    return (0);
}