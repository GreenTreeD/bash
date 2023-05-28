// Any chessman super base class declaration 
#ifndef CHESSMAN
#define CHESSMAN

#include <iostream>

class Figure {
  protected:
    char pos[2]; // board position [a-h][1-8]
  public:
    Figure(char*);                 // Figure pos constructor
    Figure() {};                   // need to multy inherit
    virtual int attack(char*)=0;   // pure attack
    virtual char isa()=0;          // virtual type
    static int deskout(char*);     // check desk out space
    int danger();                  // show danger squares
    Figure& operator=(char*);      // as repos
    int operator==(char*);         // this busy position
    int operator!=(char*);         // this other position
    friend std::ostream& operator<<(std::ostream&, Figure&);
    friend std::istream& operator>>(std::istream&, Figure&);
}; // Figure
#endif
