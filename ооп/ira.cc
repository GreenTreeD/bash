#include <iostream>
using namespace std;

class N {
protected:
    int t;
public:
    N() {t = 0;};
    virtual void print(){cout<<"N::print"<<endl;};
};

class V : public N {
public:
    //V() {};
    void print(){cout<<"V::print    t = "<<t<<endl;};
};

int main () {
    N n;
    V v;
    N *pn;
    V *pv = &v;
    pn = &n;

    //N *pn=&n;
    pn->print();
    pn = &v;
    pn->print();
}