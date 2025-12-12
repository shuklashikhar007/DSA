// yaha pe we can buy a stock only if we have sold the previous one
// yaha pe 3D DP lagegi 
#include<bits/stdc++.h>
using namespace std;
int f(int ind, int buy,int cap, vector<int>&arr, vector<vector<vector<int>>> &dp){
    if(ind == arr.size()){
        return 0;
    }
    // agar call me buy = 1 matlab stock kharidna hai
    // agar call me buy = 0 matlab we have to sell thestock
    if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
    int profit  = 0;
    if(buy){ // agar uss index par stock buy kiya to
        profit = max(-arr[ind]  + f(ind+1,0,cap,arr,dp) , f(ind+1,1,cap,arr,dp));
    }
    else{ // agar uss index pe hamne stock sell kiya to
        // do options ya to sell karege ya to nahi karege
        profit = max(arr[ind] + f(ind+1, 1,cap-1,arr,dp), 0 + f(ind+1,0,cap,arr,dp));
    }
    return dp[ind][buy][cap] = profit;
}
int R(vector<int>&arr, int cap){
    int n = arr.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int>(3,-1)));
    int ans = f(0,1,cap,arr,dp);
    return ans;
}
int main(){
    int n,k;
    cin >> n >> k;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    int profit = R(arr,k);
    cout << profit <<  endl;
    return 0;
}