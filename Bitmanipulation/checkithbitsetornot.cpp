// Brute force solution to check if the ith bit is set ( equal to 1 ) or not 
#include<bits/stdc++.h>
using namespace std;
bool check(int n, int bit){
    string binary = "";
    // no ko binary representation mai convert kardo
    while (n>0)
    {
        binary += (n%2 == 0 ?'0' : '1');
        n = n/2; // abb agli but pe move kare   
    }
    if(bit >= binary.size()) return false; // req bit string se badi hai to iskamatlba whaha pakka 0 hoga
    // return false;
    return (binary[bit] == '1') ; // agar req bit 1 hai to return true;

}
int main(){
    int n;
    cin >> n;
    // bit is in 0 based indexing
    int bit; cin >> bit;
    if(check(n,bit)){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
    return 0;
}