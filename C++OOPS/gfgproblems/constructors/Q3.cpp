#include<iostream>
using namespace std;
/// copy constructor hamesa const refer object hi lega 
class Test
{
public:
   Test(Test &t) { }
   Test()        { }
};

Test fun()
{
    cout << "fun() Called \n";
    Test t;
    return t;
}

int main()
{
    Test t1;
   // Test t2 = fun();
    return 0;
}