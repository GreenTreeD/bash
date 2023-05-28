#include <iostream>
using namespace std;


class Base{
public:
	virtual int yeet() = 0;
	virtual int bipbip(){
		cout << "AAAAAAAAAAAAAAAAA"<< endl;
		return 0;};

};

class St1: virtual public Base{
public:
	virtual int yeet(){cout << "St1::yeet\n"; return 1;};
};

class St2: virtual public Base{
public:
	virtual int yeet(){cout << "St2::yeet\n"; return 2;};
};

class bipka: public St1, public St2{
public:
	int yeet() override{
		St1::yeet();
		St2::yeet();
		return 3;
	}
	virtual int bipbip() {
		cout << "bip" << endl;
		return 0;
	} 
};
class Ass{
	friend bipka;
	int zhopa;
public:
	static int popa(){
		bipka l;
		l.bipbip();
	cout << "a nycho pystat ne budu(((" << endl;
	return 0;	
	}
};


int main() {
	bipka l;
	Base * pn;
	pn = &l;
	pn->yeet();
	l.bipbip();
	Ass m;
	m.popa();

	
}
