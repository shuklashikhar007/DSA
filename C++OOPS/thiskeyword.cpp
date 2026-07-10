#include<iostream>
using namespace std;

class Test
{
private:
  int x;
public:
  Test(int x = 0) { this->x = x; }
 // void change(Test *t) { this = t; } is line mai error hai because this ek const pointer hota hai hamesa 
 // this is always passed secretly to all non static member functions 
  void print() { cout << "x = " << x << endl; }
};
//  static function and tries to access this pointer. this pointer is not available to static member functions as static member function can be called without any object.
int main()
{
  Test obj(5);
  Test *ptr = new Test (10);
 // obj.change(ptr);
  obj.print();
  return 0;
}