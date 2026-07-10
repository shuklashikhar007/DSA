#include <iostream>
using namespace std;

class Animal
{
public:
    virtual ~Animal()
    {
        cout<<"Animal destroyed\n";
    }
};

class Dog : public Animal
{
public:
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