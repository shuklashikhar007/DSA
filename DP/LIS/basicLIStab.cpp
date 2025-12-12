#include<bits/stdc++.h>
using namespace std;
int LIS(vector<int>&a){
    int n = a.size();
    vector<int>dp(n,1); // dp[i] = LIS ending at index i
    int ans = INT_MIN;
    for(int i=0;i<n;i++){
        for(int prev = 0; prev < i ; prev++){
            if(a[i] > a[prev]){
                dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }
        ans = max(ans, dp[i]);
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