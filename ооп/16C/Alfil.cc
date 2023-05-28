#include "Alfil.h"


Alfil::Alfil(){};
Alfil::Alfil(char* p):Figure(p){};
char Alfil::isa() {
        return 'A';};
int Alfil::attack(char * p) {
    int x = p[0] - pos[0];
    int y = p[1] - pos[1];
    if (x < 0) x = -x;
    if (y < 0) y = -y;
    if ((x == 2)&&(y == 2 )) return 1;
    return 0;
}