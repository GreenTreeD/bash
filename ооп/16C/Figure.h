#ifndef FIGURE
#define FIGURE

class Figure {
protected:
    char pos[2];
public:
    Figure();
    Figure(char *a);
    Figure& operator=(char*);  
    virtual char isa() = 0;
    virtual int attack(char *) = 0;
    int operator != (char *);
    void desk();
};
#endif

