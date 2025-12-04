// yaha pe we have to partition the set into two subsets such that
// the difference between thier sum values is minimum
// partition a set into two subsets with min absolute sum difference 
// yaha pe tabulation approach lagegi
// from the DP array we can know all possible values of S1 
// from totalsum - s1 we can know all possible values of S2
// since we know all possible values of S1 and S2 we can know all possible values of S1-S2;
// then we can select the min possible value of S1 - S2 from the obtained values

#include<bits/stdc++.h>
using namespace std;
bool subsetsumutil(int ind, int target, vector<int>&arr, vector<vector<int>> &dp){
    // ye function is similar to the problem when we are given a array and a target sum to check whether that sum can be made from that
    // array or not
    // Base cases
    if(target == 0){
        return true;
    }   
    if(ind == 0){
        return (arr[0] == target);
    }
    if(dp[ind][target] != -1){
        return dp[ind][target]; // memoization
    }

    bool nottake = 0 + subsetsumutil(ind-1, target,arr,dp);
    bool take = false;
    if(arr[ind] <= target) take = arr[ind] + subsetsumutil(ind-1,target- arr[ind],arr,dp);
    return (dp[ind][target] = take || nottake);
}
int minsubsetdiff(vector<int>&arr, int n){
    int totalsum = 0;

    for(int i=0;i<n;i++){
        totalsum += arr[i];
    }
    vector<vector<int>> dp(n, vector<int>(totalsum+1,-1));
    // abb store or false (whether it is possible to create) the target sum form 0 to totalsum
    for(int i=0;i<=totalsum;i++){
        bool dummy = subsetsumutil(n-1,i,arr,dp);
    }
    int mini = INT_MAX;
    for(int i=0;i<=totalsum;i++){
        if(dp[n-1][i] == true){
            // yaha pe dp[n-1][i] represents ki kya n-1 index size ki array se i target sum banaya ja sakta hai ?
            // if true that means that S1 exists 
            int S2 = abs(i - (totalsum-i));
            mini = min(mini,S2);
        }
    }

    return mini; // yahi hoga min possible absolute difference 
}
int main(){
    vector<int>arr = {1,2,3,4,5};
    int n = arr.size();
    int ans = minsubsetdiff(arr,n);
    cout << ans << endl;
    return 0;
}