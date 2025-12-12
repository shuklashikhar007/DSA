// tabulation solution to the problem 
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    int profit = 0;
    vector<vector<int>> dp(n+1,vector<int>(2,-1));
    // base cases
    for(int i=0;i<2;i++) dp[n][i] = 0;
    // copy the recursion
    for(int i = n-1 ; i >= 0 ; i--){
        for(int buy = 0 ; buy < 2; buy++){
            int profit = 0;
            if(buy){
                profit = max(-arr[i] + dp[i+1][0] , dp[i+1][1]);
            }
            else profit = max(arr[i] + dp[i+2][1], dp[i+1][0]);
            dp[i][buy] = profit;
        }
    }
    cout << dp[0][1] << endl;
    return 0;
}