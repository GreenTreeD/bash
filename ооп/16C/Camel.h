#ifndef CAMEL
#define CAMEL

#include "Figure.h"

class Camel : virtual public Figure {

public:
    Camel();
    Camel(char*);
    virtual char isa();
    int attack(char *);
};

#endif