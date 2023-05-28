#include <stdio.h>
#include <stdlib.h>

class Point
{
  const int x;
  const int y;

public:

  Point(int xx, int yy):x(xx),y(yy){};
  int GetX(){ return x; };
  int GetY(){ return y; };

  friend int differ (const void*, const void*);
  int differ (const Point*);

};

inline int Point::differ(const Point *p){
  return(p->x - x);
}

int differ(const void *pp, const void *qq){
  Point **p = (Point**) pp;
  Point **q = (Point**) qq;

  return p[0]->y - q[0]->y;

}


int main (int argc, char* argv[]) 
{
  Point** p;
  int x, y;
  int i = 0;
  int j;
  int n = 0;


if(argc < 2)
 return (-1);

p = new Point*[argc - 1];

while (++i < argc)
{
  x = y = 0;
  sscanf(argv[i], "%d%*c%d", &x, &y);
  p[n++] = new Point (x, y);
}

//qsort ( void * first, size_t number, size_t size, int ( * comparator ) ( const void *, const void * ) );
// возвращает значения <0 , =0 и >0


for (i = 0; i < n; i++) {
  printf("(%d;%d) ", p[i]->GetX(), p[i]->GetY());
}

printf("\n");



qsort((void*)p,n,sizeof(Point*), differ);


for (i = 0; i < n; i++) {
  printf("(%d;%d) ", p[i]->GetX(), p[i]->GetY());
}

printf("\n");

for (i=0; i<n; i++)
{
printf("(%d;%d) >", p[i]->GetX(), p[i]->GetY());
for (j=0; differ(&p[j], &p[i]) < 0; j++)
 if (p[i]->differ(p[j]) < 0)
  printf (" (%d;%d)", p[j]->GetX(), p[j]->GetY());
putchar ('\n');
}

for (i=0; i<n; i++)
 delete p[i];
delete []p;
return 0;


}
