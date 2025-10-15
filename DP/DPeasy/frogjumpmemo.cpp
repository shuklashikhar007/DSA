// Memoization approach ke liye we need overlapping subproblems
#include<bits/stdc++.h>
using namespace std;
int solve(int ind, vector<int>& height, vector<int>&dp){
    if(ind == 0){
        return 0;
    }
    if(dp[ind] != -1) return dp[ind]; // yaha pe memoization hoga
    int jumptwo = INT_MAX;
    int jumpone = solve(ind - 1, height,dp) + abs(height[ind] - height[ind-1]);
    if(ind > 1){
        jumptwo = solve(ind-2, height,dp) + abs(height[ind] - height[ind-2]);
    }
    return dp[ind] =min(jumpone,jumptwo);
}
int main(){
    vector<int>height = {30,10,60,10,60,50};
    int n = height.size();
    vector<int>dp(n,-1);
    cout << solve(n-1,height,dp);
    return 0;
}
