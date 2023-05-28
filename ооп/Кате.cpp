#include <cctype>
#include <iostream>
using namespace std;


class Alpha
{
private:
    unsigned bin;
public:

    Alpha() {bin=0;};
    Alpha(char*);


    Alpha operator ~ (); // переопределение ~ 
    Alpha operator * (const Alpha); // переопределение *
    friend ostream & operator << (ostream &, Alpha);
};



Alpha::Alpha(char* s)
{
    bin=0;
    while(*s)
    {
        bin |= (1 << (tolower(*s)-'a'));
        s++;
    }
}

Alpha Alpha::operator * (const Alpha b) {
    Alpha temp;
    temp.bin = bin * b.bin;
    return temp;
}

Alpha Alpha::operator ~ () {
    Alpha temp;
    temp.bin = ~bin;
    return temp;
}

ostream & operator<< (ostream & out, Alpha x) {
    unsigned a = x.bin;
    char st[28];
    int i = 0;
    int c = 0;
    while (a > 0 && c <= 26){
        if (a & 1){
            out << (char) ('a'+c); 
        }
        a = a >> 1;
        c++;
    }

    return out;
}


int main (int argc, char* argv[])
{
    if (argc != 3) {
        cout << "Usage: <string1> <string2>" << endl;
        return -1;
    }
    Alpha x(argv[1]);
    Alpha y(argv[2]);
    Alpha z;
    z = x*y;
    z = ~z;
    cout << z << endl;
    return (0);
}