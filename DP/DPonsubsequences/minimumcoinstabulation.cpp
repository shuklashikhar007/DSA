#include<bits/stdc++.h>
using namespace std;
int noofways(vector<int>&coins , int target){
    const int INF = 1e9;
    int n = coins.size();
    vector<vector<int>> dp(n , vector<int>(target+1,INF));
    for(int i = 0; i < n ; i++){
        dp[i][0] = 0; // agar target zero hai required no of coins is always 0
    }
    for(int t = 0; t < target;t++){
        dp[0][t] = (t%coins[0] == 0 ? t / coins[0] : INF);
    }
    for(int i = 1; i < n; i++){
        for(int t = 0; t <= target; t++){
            int nottake = dp[i-1][t];
            int take = INF;
            if(coins[i] <= t && dp[i][t-coins[i]] < INF){
                take = 1 + dp[i][t-coins[i]];
            }
            dp[i][t] = min(nottake, take);
        }
    }
    return dp[n-1][target] >= INF ? -1 : dp[n-1][target];
}
int main(){
    vector<int>coins = {1,2,3};
    int target = 8;
    int ans  = noofways(coins,target);
    cout << ans << endl;
    return 0;
}