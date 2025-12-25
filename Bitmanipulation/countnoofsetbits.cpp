// Brute force wala tarika
#include<bits/stdc++.h>
using namespace std;
int noofset(int n){
    int cnt = 0;
    while (n>0)
    {
        cnt += (n&1); // kyoki agar LSB( last significant bit 1 hogi tabhi ye 1 ayega )
        n = n >> 1; // right shift all bits by 1 
        // right shifting se eventually no o ho jayega   
    }
    // T.C -> O(jitni bit range 32 or 64 ops honge)
    return cnt;
}
int main(){
    int n;
    cin >> n;
    int ans = noofset(n);
    cout << "The number of set bit's are : " << ans << endl;
    return 0;

}