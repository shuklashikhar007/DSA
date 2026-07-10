#include <iostream>
using namespace std;

class Print
{
public:

    void show(int x) // arg alag hone chaiye sirf return type alag hone se
    // overloading nahi hogi
    {
        cout<<"Integer "<<x<<endl;
    }

    void show(double x)
    {
        cout<<"Double "<<x<<endl;
    }

    void show(string s)
    {
        cout<<"String "<<s<<endl;
    }
};

int main()
{
    Print p;

    p.show(5);
    p.show(5.6);
    p.show("Hello");
}