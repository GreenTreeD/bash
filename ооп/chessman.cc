


// Super base Chessman methods (+3 to WordPad print)

#include "chessman.h"

using std::cout;

// Figure constructor
Figure::Figure(char* p) {
pos[0] = p[0]; pos[1] = p[1];
} // Figure(char*)

// Check pointed position out from the desk
int Figure::deskout(char* p) {
return ((p[0] > 'h') || (p[0] < 'a') || (p[1] < '1') || (p[1] > '8'));
} // deskout()

// operator this reposition
Figure& Figure::operator=(char* p) {
pos[0] = p[0]; pos[1] = p[1];
return (*this);
} // =()

// Check this Figure is busy pointed position
int Figure::operator==(char* p) {
return((pos[0] == p[0]) && (pos[1] == p[1]));
} // ==()

// There is no this figure in pointed position
int Figure::operator!=(char* p) {
return((pos[0] != p[0]) || (pos[1] != p[1]));
} // !=()

// Print Figure name & position by chess notation
std::ostream& operator<<(std::ostream& out, Figure& f) {
return out << f.isa() << f.pos[0] << f.pos[1];
} // <<()

// Input Figure position by chess notation
std::istream& operator>>(std::istream& in, Figure& f) {
char s[2];           // to new position control
std::cin.unsetf(std::ios::skipws); // veto input spaces
in >> s[0] >> s[1];                // input position
in.ignore(64, '\n');               // purge more 2 char input
if((f.attack(s) == 0) || (f == s)) // move control, if(f.deskout(s))  // or deskout control only
    in.clear(std::ios::failbit | in.rdstate()); // set fail state
f = s;                        //  reset position as f.repos(s); 
return in;
} // >>()

// Show danger to board squares from this Figure
int Figure::danger() {
int i, j;           // desk squares indexes
char s[2];          // square coord
char* mark = (char*)".+x"; // marker attack set mark[0]='.'
char m;             // square marker
cout << "  a b c d e f g h\n"; // black side vertical alphas
for(i=8; i > 0; i--) {         // board horizon scan 8-1
  cout << i << ' ';            // left board horison number
  s[1] = '0' + i;              // horizon digit [8-1]
  for(j=0; j < 8; j++) {       // board vertical scan
    s[0] = 'a' + j;            // vertical alpha [a-h]
    m = (*this != s) ? mark[attack(s)] : isa(); // attack ?
    cout << m << ' ';          // mark position
  } // for-j
  cout << i << "\n";           // right board horizon number
} // for-i
cout << "  a b c d e f g h\n"; // white side vertical alphas
return(0);
} // Figure::danger
