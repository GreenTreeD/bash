#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;
int euclide (int, int);
class Fraction {
private:
    int nom;
    int den;
public:
    Fraction(int n = 0 , int m = 1) :nom(n), den(m) {};
    Fraction(char*);
    void reduce();
    operator char* ();
    Fraction operator ~();

};
Fraction::Fraction(char* s) {
    char* p = strchr(s, '/');
    if (p != NULL) {
        *p++ = '\0';
        den = atoi(p);
    }
    nom = atoi(s);
}
int euclide(int n, int m) {
    int r = 1;
    while (n != 0) {
        r = m % n;
        m = n;
        n = r;
        
    } return m;
}
void Fraction::reduce(){
    int gcd;
    gcd = euclide(abs(nom), den);
    nom /= gcd;
    den /= gcd;
    return;
}
Fraction::operator char* () {
    static char s[32];
    sprintf(s, "%d/%d", nom, den);
    return s;
}
Fraction Fraction:: operator ~() {
    int k = 0;
    int sign = (nom < 0) ? -1 : 1;
    int n = sign * nom;
    while (k < n) {
        k += den;
        n = k - n;

    }
    return Fraction(n * sign, den);
}
int main(int argc, char* argv[]) {
    if (argc  < 2) {
        return(puts("Usage: ./a.out 13/17"));
    }
    Fraction x(argv[1]);
    Fraction y;
    x.reduce();
    y = ~x;
    cout << (char*)y << endl;
    return 0;
}