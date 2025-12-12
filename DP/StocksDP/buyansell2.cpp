// yaha pe we can buy a stock only if we have sold the previous one
#include<bits/stdc++.h>
using namespace std;
int f(int ind, int buy, vector<int>&arr, vector<vector<int>> &dp){
    if(ind == arr.size()){
        return 0;
    }
    // agar call me buy = 1 matlab stock kharidna hai
    // agar call me buy = 0 matlab we have to sell thestock
    if(dp[ind][buy] != -1) return dp[ind][buy];
    int profit  = 0;
    if(buy){ // agar uss index par stock buy kiya to
        profit = max(-arr[ind]  + f(ind+1,0,arr,dp) , f(ind+1,1,arr,dp));
    }
    else{ // agar uss index pe hamne stock sell kiya to
        // do options ya to sell karege ya to nahi karege
        profit = max(arr[ind] + f(ind+1, 1,arr,dp), 0 + f(ind+1,0,arr,dp));
    }
    return dp[ind][buy] = profit;
}
int R(vector<int>&arr){
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(2,-1));
    int ans = f(0,1,arr,dp);
    return ans;
}
int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    int profit = R(arr);
    cout << profit <<  endl;
    return 0;
}