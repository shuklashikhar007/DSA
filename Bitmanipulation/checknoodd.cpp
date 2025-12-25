#include<bits/stdc++.h>
using namespace std;
int bit(int n){
    int bitmask = 1 << 0;
    if(n& bitmask != 0) return true;
    else return false;
}
int main(){

    /*
    int n;
    cin >> n;
    if(n% 2 == 0) cout << "EVEN" << endl;
    else cout << "ODD" << endl;
    // ye modulo wala tarika hai
    */

    // agar bit se karna hai to we will check 0thbit of the binary

    int n;
    cin  >> n;
    int check  = bit(n);
    if(check) cout << "YES" << " " << "ODD" << endl;
    else cout << "NAHI EVEN HAI" << endl;
    return 0;
}