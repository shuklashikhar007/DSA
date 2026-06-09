#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> generateSubsetSums(vector<ll>& arr) {
    int n = arr.size();
    vector<ll> sums;
    for (int mask = 0; mask < (1 << n); mask++) {
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                sum += arr[i];
            }
        }
       sums.push_back(sum);
    }
    return sums;
}
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll totalSum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        totalSum += a[i];
    }
    int mid = n / 2;
    vector<ll> left(a.begin(), a.begin() + mid);
    vector<ll> right(a.begin() + mid, a.end());
    vector<ll> leftSums = generateSubsetSums(left);
    vector<ll> rightSums = generateSubsetSums(right);
    sort(rightSums.begin(), rightSums.end());
    ll ans = LLONG_MAX;
    for (ll x : leftSums) {
        ll target = totalSum / 2 - x;
        auto it = lower_bound(rightSums.begin(), rightSums.end(), target);
        if (it != rightSums.end()) {
            ll subsetSum = x + *it;
            ans = min(ans, llabs(totalSum - 2 * subsetSum));
        }
        if (it != rightSums.begin()) {
            --it;


            
            ll subsetSum = x + *it;
            ans = min(ans, llabs(totalSum - 2 * subsetSum));
        }
    }
    cout << ans << '\n';
    return 0;
}