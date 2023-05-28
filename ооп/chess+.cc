// Fairy Chess: Plus(+) U Cros(x) = Star complex attack

#include <iostream>
#include "chesslib.h"


int main(int argc, char* argv[]) {
if(argc < 2)         // Control init Figure position
  argv[1] = (char*)("nil");   // when no one argument
if(Figure::deskout(argv[1])) {// init correction
  std::cout << "Correct " << argv[1];
  std::cout << " to " << (argv[1] = (char*)"a1") << " Default\n";
  std::cout << "Usage example: chess+ e5\n";
} // if
Marquis f(argv[1]);    // Star init positon
do {                // scan board for Star attack
  f.danger();       // Star composite dangeres      
  std::cout << f << '-' << f.isa(); // Star move to ?
} while (std::cin >> f); // input new Figure position
return(0);
} // main
