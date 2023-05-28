#include <stdlib.h>
#include <stdio.h>


class Quadrat {
  protected:
    unsigned** tab;
    int degree;  
  public:
    Quadrat(int);
    ~Quadrat();
}; 

class Magic : public Quadrat {
  public:
    Magic(int);
    ~Magic();      // optional
    void print();
    void control();
    void terrasbashe();
  private:
    int width();
    int linechk();
    int diagchk();
};

int reflect(int, int);

Quadrat::Quadrat(int n) {
degree = n;
tab = new unsigned* [degree];
for(int row=0; row < degree; row++)
  tab[row] = new unsigned [degree];
for(int row=0; row < degree; row++)
  for(int col=0; col < degree; col++)
    tab[row][col] = 0;
puts("Quadrat Constuctor: Alloc & 0-init");
} 


Quadrat::~Quadrat() {
for(int row=0; row < degree; row++)
  delete [] tab[row];
delete [] tab;
puts("Quadrat Destructor: Memory Free");
}


Magic::Magic(int n) : Quadrat(n) {
puts("Magic constructor");
}


Magic::~Magic() {
puts("Optional Magic destructor");
}

 
int Magic::width() {
  int degree2;
  int len = 0;
  degree2 = (degree * degree);
  while(degree2 > 0) {
    degree2 /= 10;
    len++;
  }
  return(len);
}

void Magic::print() {
  int len = 0;
  putchar('\n');
  len = width();
  for(int row=0; row < degree; row++) {
    for(int col=0; col < degree; col++)
      printf("%0*d ", len, tab[row][col]);
    putchar('\n');
  }
  putchar('\n');
  return;
}

int reflect(int cord, int degree) {
  if (cord <= degree/2) {
    return cord + degree;
  }
  else {
    return cord - degree;
  }
  return 0;
  
}

void Magic::terrasbashe() {
  printf("Method: terras bashe\n");
  unsigned og_ext[degree*2 -1][degree*2 -1] = {0};
  for (int i = 0;i < degree*2 - 1; i++ ) {
    for (int j = 0; j < degree*2 - 1; j++) {
      og_ext[j][i] = 0;
    }
  }
  int c = 1;
  int dj = 0, di;
  for (int i = 0; i < degree; i++) {
    di = degree - 1;
    for (int j = 0; j < degree; j++) {
      og_ext[2*degree-2-(dj+j)][i+di] = c;
      c++;
      di-=1;
    }
    dj+=1;
  }
  for(int i = 0; i < degree*2 - 1; i++) {
    for (int j = 0; j < degree*2 - 1; j++) {
      if (og_ext[i][j] == 0) {
        continue;
      }
      if ((i < degree/2) || (i > degree+degree/2-1)) {
        og_ext[reflect(i, degree)][j] = og_ext[i][j];

      }
      if ((j < degree/2)||(j > degree+degree/2-1)) {
        og_ext[i][reflect(j, degree)] = og_ext[i][j];
      }
    }
  }
  for (int i = 0; i < degree; i++) {
    for (int j = 0; j < degree; j++) {
      tab[i][j] = og_ext[i+degree/2][j+degree/2];
    }
  }
}


int Magic::linechk() {
  int s;
  for(int i=0; i < degree; i++) {
    s = 0;
    for(int j=0; j < degree; j++)
      s += tab[i][j];
    printf("%d ", s);
  }
  return(s);
}

int Magic::diagchk() {
  int s[2] = {0, 0};
  int loc = (degree - 1);
  int row, col;
  for(row=col=0; row < degree; row++, col++, loc-- ) {
    s[0] += tab[row][col];
    s[1] += tab[row][loc];
  } 
  printf("%d %d", s[0], s[1]);
  return(s[0]);
} 

void Magic::control() {
  int s; // summa
  puts("Magic constant checking for row");
  linechk();
  putchar('\n');
  puts("Magic constant checking for column");
  linechk();
  putchar('\n'); 
  puts("Magic constant diagonal control");
  diagchk();
  putchar('\n'); putchar('\n');
  return;
}



int main(int argc, char* argv[]) {
  if(argc != 2)
    return(puts("Usage: magic degree"));
  int n = atoi(argv[1]);
  n = (n < 0) ? -n : n;
  if((n % 2) == 0) {
    puts("Usage: magic 5 (or 7, 11, 17, 19, 23, ...)");
    return(n);
  }
  Magic mag(n);
  mag.terrasbashe();
  mag.print();
  mag.control();
  return(n);
}
