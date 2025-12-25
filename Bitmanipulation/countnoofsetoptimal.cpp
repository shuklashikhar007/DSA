// optimal approach to find no of set bits
// each iteration of n = n & (n-1) removes the rightmost setbit or rightmost 1 from the binary representation of the number
#include<bits/stdc++.h>
using namespace std;
int noofset(int n){
    int count = 0;
    while (n) // jabtak n greater than 0 hai tab tak
    {   
        n = n & (n-1);
        count++;
    }
    return count;
    // T.C - O(noofsetbits)
}
int main(){
    int n;
    cin >> n;
    int ans = noofset(n);
    cout<< ans << endl;
    return 0;
}