#include <iostream>
using namespace std;
// A copy constructor must take its argument by reference because passing by value would require calling the copy constructor again, leading to infinite recursion.
class Point
{
    int x, y;
public:
   Point(int x, int y){
        this->x = x;
        this->y = y;
   }
   Point(const Point &p) { x = p.x; y = p.y; }
   int getX() { return x; }
   int getY() { return y; }
};

int main()
{
    Point p1(10,20);
   // upar wali line error degi since agar hame koi bhi cons kisi bhi type ka bana diya 
   // to fir default wala create nahi hota hai 
    Point p2 = p1;
    cout << "x = " << p2.getX() << " y = " << p2.getY();
   // agar upar wala code chalana hai to we must make a parameter wala cons 
    return 0;
}