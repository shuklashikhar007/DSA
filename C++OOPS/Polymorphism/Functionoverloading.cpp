#include<iostream>
using namespace std;
class calculator{
    public:
    int add(int a, int b){
        return a + b;
    }
    /// same function lekin diff return type
    double add(double a, double b){
        return a+b;
    }
    int add(int a, int b, int c){
        return (a+b+c);
    }
};  
int main(){
    calculator c;
    cout << c.add(2,3) << endl;
    cout << c.add(2.5,3.5) << endl;
    cout << c.add(1,2,3);
    return 0;
}