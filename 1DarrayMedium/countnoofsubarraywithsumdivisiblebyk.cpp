#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll n;
    cin >> n;
    vector<ll>a(n);
    for(int i=0;i<n;i++){
        cin  >> a[i];
    } // prefix sum array bana lo
    vector<ll> pref(n);
    pref[0] = a[0];
    for(int i=1;i<n;i++){
        pref[i] = pref[i-1] + a[i];
    }
    map<ll,ll>mpp;
    // Bahut Important for all subarray that start from index 0
    mpp[0] = 1;
    for(int i=0;i<n;i++){
        ll mod = ((pref[i] % n) + n) % n;
        mpp[mod]++;   
    }
    ll ans = 0;
    for(auto it : mpp){
        ans += it.second*(it.second-1)/2;
    }
    cout << ans << endl;
    return 0;
}