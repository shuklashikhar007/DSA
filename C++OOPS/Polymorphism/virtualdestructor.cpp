#include <iostream>
using namespace std;

class Animal
{
public:
    Animal(){
        cout << "Base class constructor called" << endl;
    }
    virtual ~Animal()
    {
        cout<<"Animal destroyed\n";
    }
};

class Dog : public Animal
{
public:
    Dog(){
        cout << "Derived class constructor has been called" << endl;
    }
    ~Dog()
    {
        cout<<"Dog destroyed\n";
    }
};

int main()
{
    Animal *a = new Dog();

    delete a;
}