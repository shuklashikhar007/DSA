#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&arr, int i, int j, vector<vector<int>> &dp){
    if(i==j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int mincost = INT_MAX;
    for(int k = i; k <j;k++){
        int cost1 = solve(arr,i,k,dp);
        int cost2 = solve(arr,k+1,j,dp);
        int costmultiply = arr[i-1]*arr[k]*arr[j];
        int total = cost1 + cost2 + costmultiply;
        mincost = min(mincost,total);
    }
    return dp[i][j] = mincost;
}
int MCM(vector<int>&nums){
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n,-1));   
    return solve(nums,1,n-1,dp);
}
int main(){
    vector<int>nums = {10,15,20,25};
    cout << MCM(nums) << endl;
    return 0;
}