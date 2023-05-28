// Knight attack square *p (1 square by ortogonal only, as +)


#include "chesslib.h"

int Knight::attack(char* p) {
if(deskout(p) > 0)      // control pointed position
  return(0);            // square outside the desk
int x = p[0] - pos[0];  // alpha shift by row
int y = p[1] - pos[1];  // digit shift by col
if(x < 0) x = -x;       // abs delta by x
if(y < 0) y = -y;       // abs delta by y
if(((x + y) == 3)&&(x*y != 0))        // this attack to pointed
  return(1);            // position
return(0);              // this no attack to *p
} // Knight::attack

// Alfil attack square *p (1 square by diagonal only, as x)

int Alfil::attack(char* p) {
if(deskout(p) > 0)      // control pointed position
  return(0);            // square outside the desk
    int x = p[0] - pos[0];
    int y = p[1] - pos[1];
    if (x < 0) x = -x;
    if (y < 0) y = -y;
    if ((x == 2)&&(y == 2 )) return 1;
    return 0;
} // Alfil::attack

// Marquis attack square *p (compose Knight & Alfil attack)

int Marquis::attack(char* s) {
if(Knight::attack(s) > 0) // as Knight attack
  return(1);
if(Alfil::attack(s) > 0) // as Alfil attack
  return(2);
return(0);               // no attack *p
} // Marquis::attack
