#include <iostream>
using namespace std;

class Complex
{
public:
    int real;
    int imag;
    Complex(int r,int i)
    {
        real = r;
        imag = i;
    }
    Complex operator+(Complex &obj)
    {
        // Complex ans = (real + obj.real, imag + obj.imag);
        // return ans;
        return Complex(real + obj.real,
                       imag + obj.imag);
    }
    Complex operator-(Complex &obj){
        return Complex(real - obj.real, imag - obj.imag);
    }
    void print()
    {
        cout<<real<<" + "<<imag<<"i"<<endl;
    }
};

int main()
{
    Complex c1(2,3);
    Complex c2(4,5);
    Complex c3 = c1 + c2;
    Complex c4 = c1 - c2;
    c4.print();
    c3.print();
}