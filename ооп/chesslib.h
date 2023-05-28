// Fairy chessman subclasses library declaration


#ifndef CHESSLIB
#define CHESSLIB

#include "chessman.h"

// Fairy chess Knight(+) primary class

class Knight : virtual public Figure {
  public:
    Knight(char* p) : Figure(p) {};    // Knight init position
    Knight() {};                       // cosmetic
    char isa() { return 'K'; };      // Knight marker
    int attack(char*);               // Knight attack
}; // Knight

// Fairy chess Alfil(x) primary class

class Alfil : virtual public Figure {
  public:
    Alfil(char* p) : Figure(p) {};    // Alfil init position 
    Alfil() {};                       // cosmetic
    char isa() { return 'A'; };      // Alfil marker
    int attack(char*);               // Alfil attack
}; // Alfil

// Fairy Chess Marquis complex class
// Marquis(Knight(Figure), Alfil(Figure))

class Marquis : public Knight, public Alfil {
  public:
    Marquis(char* p) : Figure(p) {};       // Marquis init position
    char isa() { return 'K'; };         // Marquis marker
    int attack(char*);                  // Marquis attack
}; // Marquis

#endif
