#include <iostream>
using namespace std;
// by deafult ek class ke sare members private hote hai hamesa 
class Point {
    Point() { cout << "Constructor called"; }
};

int main()
{
   // Point t1; -> isliye ye line error degi hamesa 
    return 0;
}