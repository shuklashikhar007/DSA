#include<iostream>
using namespace std;
class Point {
    int x;
public:
    Point(int x) { this->x = x; }
   // ye niche wali line sirf isliye nahi chal rahi
   //   because p pass by reference nahi hai yaha pe
   // Point(const Point p) { x = p.x;} 
    Point(const Point &P){
        x = P.x;
    }
   int getX() { return x; }
};

int main()
{
   Point p1(10);
   Point p2 = p1;
   cout << p2.getX();
   return 0;
}