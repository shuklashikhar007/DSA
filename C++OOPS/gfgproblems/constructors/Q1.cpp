#include<bits/stdc++.h>
using namespace std;
// copy cons normal cons and assignment cons all are created by default if you don't assign them 
class point{
    public:
    point(){ // non default cons
        cout << "Normal cons called !!" << endl;
    }
    // non default copy cons 
    point(const point &t){ // copy cons decalre karne ka syntax
        // const (name of class) &t 
        cout << "copy cons called" << endl;
    }
};
int main(){
    point *t1,*t2; // ye pointer banaye hai hamne 
    // isme cons call nahi hoga kyoki ye object nahi hai
    t1 = new point(); // object banaya hai yaha pe
    t2 = new point();
    point *t3 = new point();
    point t4 = *t1; // yaha pe copy banegi to copy cons call hoga  
    point t5 = *t1;
    point t6;
    t6 = t4;
}