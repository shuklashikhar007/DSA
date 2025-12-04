// 0/1 knapsack ( take or not take type problem )
#include<bits/stdc++.h>
using namespace std;
int knap(int ind, int bagw, vector<int>& weights, vector<int>& values, vector<vector<int>> &dp){
    if(bagw <= 0) return 0; // agar kam hote hote bag ka weight 0 ya negative hogaya that means abb 
    // kuch aur chura nahi sakte hai hum
    if(ind == 0){
        if(weights[0] <= bagw) return values[0];
        return 0; // agar last element ki value bag ke max capacity se jydada hai then we cannot steal that
    }
    if(dp[ind][bagw] != -1) return dp[ind][bagw];
    int nottake = knap(ind - 1, bagw, weights, values,dp);
    int take = 0;
    if(weights[ind] <= bagw){
        take = values[ind] + knap(ind - 1, bagw - weights[ind], weights, values,dp);
    }
    dp[ind][bagw] = max(take , nottake);
    return dp[ind][bagw];
}
int main(){
    vector<int> w = {3,2,4,5};
    vector<int> values = {4,3,5,6};
    int n = w.size();
    int W = 8; // chori karne wale bag ki capacity 
    vector<vector<int>> dp(n, vector<int>(W+1, -1));
    int maxvalue = knap(n-1,W,w,values,dp);
    cout << "Chori ka max possible amount " << maxvalue << endl;
    return 0;
}