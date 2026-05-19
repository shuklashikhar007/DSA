#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll n,W;
    cin >> n >> W;
    vector<pair<ll,ll>> arr(n);
    ll tval = 0;
    for(ll i = 0; i < n;i++){
        cin >> arr[i].first >> arr[i].second;
        tval += arr[i].second;
    }
    const ll INF = 1e18;
    vector<ll>dp(tval+1, INF);
    dp[0] = 0;
    for(ll i=0 ; i<n; i++){
        ll wt = arr[i].first;
        ll val = arr[i].second;
        for(ll v = tval ; v >= val ; v--){
            dp[v] = min(dp[v], wt + dp[v-val]);
        }
    }
    ll ans= 0;
    for(ll v =0 ; v <= tval; v++){
        if(dp[v] <= W){
            ans = v;
        }
    }
    cout << ans << endl;
    return 0;
}