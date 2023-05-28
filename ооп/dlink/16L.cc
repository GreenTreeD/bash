#include  <stdio.h>
#include  <stdlib.h>
#include  "dlink.h"

class SymLink : public Dlink {
private:
    unsigned char sym;
public:
    SymLink(unsigned char c) : Dlink(), sym(c) {};
    SymLink* incr() {return((SymLink*) Dlink::incr());};
    int print();	// печать элементов списка
    SymLink* append(SymLink* q){return((SymLink*)Dlink::append(q));};
};

// Печать  и  подсчет  элементов  от начала до конца списка
int SymLink::print() {
    SymLink* p = this; 
    SymLink* q; 
    int n= 0;
    while(p != NULL){
        putchar(p->sym);
        q = p->incr();
        p = q;
        n++;
    }
    putchar('\n');
    return(n);
}

int main(int argc, char* argv[]) {
    SymLink* head0; // список символос с нулевым разрядом
    SymLink* head1; // список символов с единичным разрядом
    SymLink* temp;
    SymLink* q;

    char c;
    printf("Введите строку:\n");    
    while ((c = getchar()) != EOF) {
        if (c % 2 == 0) {
            q = new SymLink(c);
            head0 = head0->append(q);
        }
        else {
            q = new SymLink(c);
            head1 = head1->append(q);
        }
    }
    printf("\n===========\n");
    head0->print();
    printf("0\n");
    head1->print();
    printf("1\n");
    printf("===========\n");
} 
