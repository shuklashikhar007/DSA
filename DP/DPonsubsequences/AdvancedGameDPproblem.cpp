// k STONES ATCODER 
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    vector<int>dp(k+1,0);
    dp[0]=0; // o stones ek losing state hogi hamesa
    // agar ham apne opponent ke liye losing state chord ke jaye hamesa then
    // we will always end up winning from point of view of the first player
    // ye question ham solve bhi first ke POV se hi kar rahe hai wese 
    for(int i=0;i<=k;i++){
        for(int x : a){
            if(i >= x && dp[i-x] == 0){
                dp[i] = 1;
            }
        }
    }
    if(dp[k]) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}