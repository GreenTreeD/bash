#include "Camel.h"


Camel::Camel(){};
Camel::Camel(char* p):Figure(p){}
char Camel::isa() {return 'C';}


int Camel::attack(char * p) {
    int x = p[0] - pos[0];
    int y = p[1] - pos[1];
    if (x < 0) x = -x;
    if (y < 0) y = -y;
    if (((x+y) == 4)&&((x*y)%2 != 0)) return 1;
    return 0;
}
