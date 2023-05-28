#include <stdio.h>
#include <cmath>
#include <math.h>
#include <stdlib.h>

#define sq(x) (x)*(x)

class Vertex {
    private:
        
        int x;
        int y;
        
    public:
        
        Vertex(){ x = 0; y = 0; }
        Vertex(int X, int Y): x(X), y(Y) { }
        int GetX() {return x;}
        int GetY() {return y;}
        void Set(int a, int b) {x = a;y = b;}
        double Distance(Vertex *a) { return sqrt(sq(x-a->x)+sq(y-a->y)); };
};

int main(int argc, char **argv) {
	int i = 0;
	int j = 0;
	int countxm = 0;
	int countxp = 0;
	Vertex **p, **xm, **xp, *a, *b;
	int x,y;
	double maxdist;


	if(argc < 2) { 
		printf("Not enough arguments.\n");
		return(-1); }
	p = new Vertex*[argc-1];

	while(++i < argc) {
		sscanf(argv[i], "%d%*c%d", &x, &y);
		p[j] = new Vertex(x,y);
		j++;
		if (x >= 0) { countxp+=1; }
		else { countxm+=1; } }
	i = 0;

	xm = new Vertex*[countxm+1];
	xp = new Vertex*[countxp+1];
	countxm = 0;
	countxp = 0;

	while(i < argc-1) {
		if (p[i]->GetX() >= 0) { xp[countxp++] = p[i];	}
		else { xm[countxm++] = p[i]; }
		i++; }

	xp[countxp] = NULL;
	xm[countxm] = NULL;

	delete []p;

	if ((countxm < 1) || (countxp < 1)) {
		printf("No such points\n");
	}
	else {
		for(i = 0; i < countxp; i++) {
			for(j = 0; j < countxm; j++) {
				if (xp[i]->Distance(xm[j]) > maxdist) { 
					maxdist = xp[i]->Distance(xm[j]);
					a = xp[i];
					b = xm[j];
				 }
			}
		}
		printf("Point A: %d:%d\nPoint B: %d:%d\nDistance: %.3lf\n", a->GetX(), a->GetY(), b->GetX(), b->GetY(), a->Distance(b));
	}
	for(i = 0; i < countxp; i++) { delete xp[i]; }
	for(j = 0; j < countxm; j++) { delete xm[j]; }
	delete []xp;
	delete []xm;
}