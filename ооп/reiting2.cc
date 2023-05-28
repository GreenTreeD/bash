#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int nod(int, int);

class Num {
private:
    int m;
    int n;
public:
    Num(int a = 0, int b = 1): m(a), n(b){}; // конструктор по умолчанию
    Num(char *); // конструктор преобразования
    void Reduce(); // метод уменьшения (жопы) дроби
    operator char*(); // преведение типа

    Num operator ~ (); // унарная операция дополнения до целого числа
    Num operator + (Num); // сложение
    Num operator - (Num); // разность
    Num operator * (Num); // умножение
    Num operator / (Num); // деление

    friend Num operator + (int, Num);

    Num operator ++(int){ // постфиксный инеремент
        Num temp(m,n);
        m+=n;
        return temp;
    };
    Num operator ++(){ // префиксный инкремент
        m+=n;
        return *this;
    };

    friend ostream & operator << (ostream &, Num); // перегрузка вывода
};

ostream & operator<< (ostream & out, Num x) {
    out << x.m << '/' << x.n;
    return out;
}


Num operator + (int a, Num b) {
    int r1, d;
    r1 = a* b.n + b.m;
    d = nod(r1, b.n);
    r1 /= d;
    return Num(r1, b.n/d);
}

Num Num::operator + (Num y) {
    int r1, r2, d;
    r1 = m*y.n + y.m*n;
    r2 = n * y.n;
    d = nod(r1, r2);
    r1 /= d;
    r2 /= d;
    return Num(r1, r2);
}

Num Num::operator - (Num y) {
    int r1, r2, d;
    r1 = m*y.n - y.m*n;
    r2 = n * y.n;
    d = nod(r1, r2);
    r1 /= d;
    r2 /= d;
    return Num(r1, r2);
}

Num Num::operator * (Num y) {
    int r1, r2, d;
    r1 = m*y.m;
    r2 = n * y.n;
    d = nod(r1, r2);
    r1 /= d;
    r2 /= d;
    return Num(r1, r2);
}


Num Num::operator / (Num y) {
    int r1, r2, d;
    r1 = m*y.n;
    r2 = n * y.m;
    d = nod(r1, r2);
    r1 /= d;
    r2 /= d;
    return Num(r1, r2);
}

Num Num::operator ~(){
    int sign = (m < 0) ? -1 : 1;
    int AA = m * sign;
    int r = 0;
    while (r < AA) {
        r+=n;
    }
    return Num(sign*(r-AA), n);
}

Num::operator char*() {
    static char s[32];
    sprintf(s, "%d/%d", m, n);
    return s;
}

void Num::Reduce() {
    int d = nod(m, n);
    m /= d;
    n /= d;
}

Num::Num(char * s) {
    char *p = strchr(s, '/');
    n = 1;
    if (p != NULL) {
        *p = '\0';
        p++;
        n = atoi(p);
    }
    m = atoi(s);
}


int nod(int a, int b){
    
    while (a*b != 0) {
        if (a > b){
            a = a % b;
        }
        else {
            b = b % a;  
        }
    }
    return (a+b);
}

int main(int argc, char ** argv) {
    if (argc < 3) {
        cout << "Usage: fraction 1 fraction 2" << endl;
        return -1;
    }
    Num a(argv[1]);
    Num b(argv[2]);
    Num add;
    add = ~a;
    cout << (char*) add << endl;
    Num n;
    n = a - b;
    cout << (char*) n << endl;
    n = 7 + a;
    cout << (char*) n << endl;
    n++;
    cout << n << endl;

    return 0;
}
