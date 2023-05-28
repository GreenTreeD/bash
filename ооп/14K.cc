#include <iostream>
using namespace std;

class Triangle;
class Point
{
    friend class Triangle;
    friend istream& operator>>(istream&, Point&);
private:
    float x;
    float y;
public:
    Point(float xx=0.0, float yy=0.0) : x(xx), y(yy) {};
};

class Triangle
{
private:
    Point p1;
    Point p2;
    Point p3;
public:
    Triangle(Point& p, Point& q, Point& t) : p1(p), p2(q), p3(t) {};
    float sq();
};

float Triangle::sq() {
    float tmp = 0.5*((p1.x-p3.x)*(p2.y-p3.y)-(p2.x-p3.x)*(p1.y-p3.y));
    tmp = tmp > 0 ? tmp : (-1)*tmp;
    return tmp;
}

istream& operator>>(istream& input, Point& p)
{
    char semicolon=';';
    input >> p.x >> semicolon >> p.y;
    return input;
}

int main()
{
    Point A, B, C;
    cout << "Input xa;ya xb;yb xc;yc or exit" << endl;
    while(cin >> A >> B >> C)
    {
        Triangle base(A,B,C);
        float sqq = base.sq();
        cout << sqq << endl;
        cout << "Input xa;ya xb;yb xc;yc or exit" << endl;
    }
    return(0);
}
