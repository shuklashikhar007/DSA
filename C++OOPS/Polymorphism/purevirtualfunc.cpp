// complete runtime poly example
#include<bits/stdc++.h>
using namespace std;
class Animal
{
public:
    virtual void speak() = 0;  // this is a pure virtual function
    // so ye wali class ek abstract class hogi 
    // is function ka implementation derived classes mai hona hi chaiye warna the code will not work properly  
};
class Dog : public Animal{
    public:
    void speak() override
    {
        cout << "Dog barks" << endl;
    }
};
class Cat : public Animal{
    public:
    void speak() override // yaha override likhna ek save practice hoti hai hamesa 
    {
        cout << "CAT meows !! " << endl;
    }
};
int main(){
    Animal *a;
    Dog d;
    Cat c;
    a = &d; // now points to dog
    a->speak();
    a = &c; // now this pointer point to cat
    a->speak();
    Animal *b;
    Dog t;
    b = &t;
    b->speak();
    return 0;
}