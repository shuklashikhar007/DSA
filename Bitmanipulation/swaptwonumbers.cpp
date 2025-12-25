#include<bits/stdc++.h>
using namespace std;
void swapxor(int &a, int &b){ // pass by refer jarur kar dena
    a = a^b;
    b = a^b;
    a = a^b;
}
int main(){
    int a = 5,b = 10;
    swapxor(a,b);
    cout << "a" << " " << a << " " <<"b " << b << endl;
    return 0;
}