// take first or last dp game
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<ll>a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    vector<vector<ll>> dp(n, vector<ll>(n,0));
    // length 1 sare base case hai
    for(int i=0;i<n;i++){
        dp[i][i] = a[i];
    }
    // len 2 se leke n tak
    for(int len = 2; len <= n; len++){
        for(int i=0;i<n-len+1;i++){
            int j = i + len - 1;
            ll left = a[i] - dp[i+1][j];
            ll right = a[j] - dp[i][j-1]; 
            dp[i][j] = max(left, right);
        }
    }
    cout << dp[0][n-1] << endl;
    return 0;
}