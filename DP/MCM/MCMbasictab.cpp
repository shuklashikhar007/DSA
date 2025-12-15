#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int MCM(vector<int>&nums){
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n,INT_MAX));
        // base cases
        for(int i=0;i<n;i++){
            dp[i][i] = 0;
        }
        for(int len = 2 ; len < n ; len++){
            for(int i=1; i<=n - len; i++){
                int j = i + len - 1;
                for(int k = i; k < j;k++){ // partition will always move from i to j - 1
                    int cost = dp[i][k] + dp[k+1][j] + nums[i-1]*nums[k]*nums[j];
                    if(cost < dp[i][j]){
                        dp[i][j] = cost;
                    }
                }
            }
        }
        return dp[1][n-1];
    }
};
int main(){
    Solution sol;
    vector<int>nums = {10,15,20,25};
    cout << sol.MCM(nums) << endl;
    return 0;
}