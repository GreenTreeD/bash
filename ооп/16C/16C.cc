#include <iostream>
#include <string.h>
#include "Figure.h"
#include "Alfil.h"
#include "Camel.h"

using namespace std;


class Don: public Alfil, public Camel {
    
public:
    Don(char * p): Figure(p){};
    char isa(){ return 'D';};
    int attack(char *);
};

int Don::attack(char* s) {
    if (Alfil::attack(s) > 0)
        return 1;
    if (Camel::attack(s) > 0)
        return 2;
    return 0;
}

int check(char *m){
    if (strlen(m)>2) {
        cout << "Error 1: invalid argument length"<< endl;
        return 1;}
    if ((m[0] < 'a') || (m[0] > 'h')) { cout << "Error 2: invalid argument format"<< endl;return 1;}
    if (!isdigit(m[1])) {cout << "Error 2: invalid argument format"<< endl;return 1;}
    return 0;

}

int main(int argc, char ** argv) {
    char pos[] = "a1";
    if (argc == 2) {
        if (check(argv[1])) {return -1;}
    pos[0] = argv[1][0];
    pos[1] = argv[1][1];}
    cout << pos << endl;
    Don f(pos);
    f.desk();
    cout << "Type new position to proceed"<< endl;
    while (cin >> pos[0] >>pos[1]){
        if (check(pos)) {
            return -1;
        }
        if (f.attack(pos) == 0) {
            cout << "Invalid position for this piece" << endl;
            return -1;
        }
        f = pos;
        f.desk();  
        cout << "Type new position to proceed"<< endl;      
    }
    return 0; 
}