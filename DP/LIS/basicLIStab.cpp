// optimized tabulation method of getting the LIS
#include<bits/stdc++.h>
using namespace std;
int LIS(vector<int>&a){
    int n = a.size();
    vector<int>dp(n,1); // dp[i] = LIS ending at index i
    int ans = INT_MIN;
    for(int i=0;i<n;i++){
        for(int prev = 0; prev < i ; prev++){
            if(a[i] > a[prev]){
                // yaha pe intution ye hai ki agar jo last element mujhe current se chota mila hai
                // agar mai cur us subsequence mai add kardu to kya DP ki value increase hogi
                dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }
        ans = max(ans, dp[i]); // a variable to maintain max value of dp
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i=0;i<n;i++)  cin >> a[i];
    cout << LIS(a) << endl;
    return 0;
}