#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>dp(n+1,1e9); // since agge jake min lenge fill with a very large number
    dp[0] = 0; // 0 ways to come to number 0
    for(int i = 1; i <= n ; i++){
        int temp = i;
        while (temp > 0)
        {
            int d = temp % 10;
            temp /= 10;
            dp[i] = min(dp[i], 1 + dp[i-d]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}
