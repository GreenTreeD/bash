#include "Figure.h"
#include <iostream>

using namespace std;

Figure::Figure(){}

int Figure::operator != (char * p ) { return ((p[0] != pos[0]) || (p[1] != pos[1])); }

Figure::Figure(char *a) {
        pos[0] = a[0];
        pos[1] = a[1];
}

Figure& Figure::operator=(char* p) {
pos[0] = p[0]; pos[1] = p[1];
return (*this);
} 

void Figure::desk(){
    int i,j;
    char s[2];
    const char* mark = ".+x";
    char m;
    cout << "  a b c d e f g h\n";
    for (i = 8; i > 0; i--){
        cout << i << ' ';
        s[1] = '0' + i;
        for(j = 0; j < 8; j++) {
            s[0] = 'a' + j;
            m = (*this != s) ? mark[attack(s)] : isa();
            cout << m << ' ';
        }
        cout << i << "\n";
    }
    cout << "  a b c d e f g h\n";
}
