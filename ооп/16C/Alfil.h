#ifndef ALFIL
#define ALFIL

#include "Figure.h"

class Alfil: virtual public Figure {

public:
    Alfil();
    Alfil(char*);
    virtual char isa();
    int attack(char *);
};

#endif