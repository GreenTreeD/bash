#include <stdlib.h>
#include <iostream>
using namespace std;

class Heap {
	int size;
public:
	Heap(int p): size(p){};
	int get(int p = 0) { // красивая фукнция которая при 
		size -=p;
		return (size);
	};
};

class Gambler {
protected:
    Heap* heap;
    const int limit;
    const char* name;
public:
	Gambler(Heap &p, int ii): limit(ii){ heap = &p;};
	virtual int move() = 0;
	int query();
    virtual ~Gambler(){}; // виртуальный деструктор
};

int Gambler::query(){ // запрос на кучу и имя игрока
	cout << "Heap = " << heap->get() << " " << name << " > ";
	return(heap->get()); 
}


class Man: public Gambler {
public:
	Man(Heap& h, int l, const char* n) : Gambler(h, l) { name = n; }
	virtual int move(); // virtual можно не писать
};

int Man::move() {
	int g;
	cin >> g;
	if ((g < 1) || (g > limit) || ( g > heap->get())) g = 1; // если было введено кривое значение, значение больше лимита или больше кол-ва в куче
	return (heap->get(g)); // забираем камушки из кучи
}


class Pen: public Gambler {
public:
	Pen(Heap& h, int l, const char* n) : Gambler(h, l) { name = n; }
	virtual int move(); // virtual можно не писать

};

int Pen::move() {

	int rest = 0;
	int x = 0;
	int h;
	if ((h = heap->get()) == 1) {
		cout << "1" << endl;
		return (heap->get());
	}
	while((rest = (x *limit + x + 1)) < h)
        x++;
    if((rest > h))
    {
        rest = (x - 1)*limit + x;
        heap->get(h - rest);
        cout << h - rest << "\n";
    }
    else
    {
        heap->get(1);
        cout << "1" << "\n";
    }
    return(heap->get());

    /* 
	как оно работает... если остался 1 камушек, то берём его и, получается, проигрываем
	если не 1, то в h висит остаток из кучи
	по выигрышной формуле считаем, сколько  надо взять
	если не вызодит, то берём 1, надеясь, что попадём в выигрышную позицию. последние 1 шага делаем, исходя из задания
    */
}

int main(int argc, char **argv){
	int i = 1;
    Heap h(atoi(argv[1]));

    Gambler* g[] = { new Pen(h, atoi(argv[2]), "Pen"), new Man(h, atoi(argv[2]), "Man")};
    while(g[i]->query() > 0) {
        g[i]->move();
        if(++i > 1)
            i = 0;
    }
    if(++i > 1) i = 0;
    cout << "0\n";
    g[i]->query();
    cout << "Loser\n";

    /* //ИЛИ
    while(g[i]->query() > 1) {
        g[i]->move();
        if(++i > 1)
            i = 0;
    }
    cout << "Loser\n";

    */
    delete g[0];
    delete g[1];

    return(0);
}