// Tabulation approach to find Length of LCS ( Not clear ) -> understand it
// is line se doubt clear -> actually mai dp table ka ith index string ke i-1th index ko represent karta hai yaha pe

#include<bits/stdc++.h>
using namespace std;
int main(){
    string a,b;
    cin >> a >> b;
    int n = a.length(), m = b.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1,0));
    // base cases
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int j=0;j<=m;j++){
        dp[0][j] = 0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1] == b[j-1]){
                dp[i][j]  = 1 + dp[i-1][j-1];
            }
            else dp[i][j] = 0 + max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout <<  dp[n][m] << endl;
    return 0;
}