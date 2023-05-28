#include <stdio.h>
#include <cmath>
#include <stdlib.h>

class Vertex {
    private:
        
        float x;
        float y;
        
    public:
        
        Vertex(){
            x = 0.0;
            y = 0.0;
        }
        
        Vertex(float X, float Y): x(X), y(Y) {
        }
        
        float GetX() {
            return x;
        }
        
        float GetY() {
            return y;
        }

        void AddCentre(Vertex a) {
            x+=a.x;
            y+=a.y;
        }
        
        void Set(float a, float b) {
            x = a;
            y = b;
        }
        
        static Vertex Polar(float, float);
};

inline Vertex Vertex::Polar(float R, float F) {
    Vertex p(R*cos(F), R*sin(F));
    return p;
}


int main(int argc, char **argv) {
    
    float edge = 1.0;
    int i = 0;
    float pi = acos(-1);
    float angle = pi/6.0;
    float radius;
    float sm = 0.0, x;
    
    Vertex mas[6];
    Vertex centre;

    if (argc > 2) {
        edge = atof(argv[1]);
        sm = atof(argv[2]);
        sm = sm/sqrt(2.0);
        centre.Set(-sm,-sm);
    }
    else {
        printf("Usage: <filename> <float edge> <float sm>\nNow using: edge = 1.0, centre(0,0)\n");
    }
    
    radius = edge; // так как у меня шестиугольник
    while (i < 6) {
        mas[i] = Vertex::Polar(edge, angle);
        mas[i].AddCentre(centre); // добавляем смещение
        angle+=pi/3.0; // поворачиваемся каждый раз на 60 градусов
        i++;
    }
    do {
        i--;
        printf("%.3f %.3f\n", mas[i].GetX(), mas[i].GetY());
    }
    while (i > 0);
    return 0;
}







