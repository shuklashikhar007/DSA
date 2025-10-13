#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// a very good question on lower and upper bound on CF
int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll a;
        vector<pair<ll, ll>> v;
        for (int i = 0; i < n; i++) {
            cin >> a;
            v.push_back({a, i});
        }
        sort(v.begin(), v.end());
        vector<ll> pre(n);
        pre[0] = v[0].first;
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + v[i].first;
        }
        vector<ll> ans(n);
        for (int i = 0; i < n; i++) {
            int j = i;
            int found = i;
            while (j < n) {
                pair<ll, ll> temp = {pre[j] + 1, INT_MIN};
                ll idx = lower_bound(v.begin(), v.end(), temp) - v.begin();
                idx--;
                if (idx == j)
                    break;
                found += idx - j;
                j = idx;
            }
            ans[v[i].second] = found;
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}