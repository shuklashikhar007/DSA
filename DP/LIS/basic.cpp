#include<bits/stdc++.h>
using namespace std;
int f(int i, int prev, vector<int>&a, vector<vector<int>> &dp){
    int n = a.size();
    if(i==n) return 0;
    if(dp[i][prev+1] != -1) return dp[i][prev+1];
    int nottake = f(i+1,prev,a,dp);
    int take =0 ;
    if(prev == -1 || a[i] > a[prev]){
        take = 1 + f(i+1,i,a,dp); // put prev = current and i to i + 1
    }
    return dp[i][prev+1] = max(take, nottake);
}
int LIS(vector<int>&a){
    int n = a.size();
    vector<vector<int>> dp(n, vector<int>(n+1,-1)); // prev jayega from -1 to n-1 which is n+1 cols and ind from o t0 n-1 which is n
    return f(0,-1,a,dp); // intially prev ind = -1 represents no prev element
}
int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    cout << LIS(arr) << endl;
    return 0;
}