#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// idx: index into price array (0..n-1), len: remaining rod length
// piece length corresponding to idx is (idx + 1)
ll rod_memo(int idx, int len, const vector<int>& price, vector<vector<ll>>& dp) {
    if (len == 0) return 0;
    if (idx == 0) {
        // only pieces of length 1 available
        return (ll)len * price[0];
    }
    if (dp[idx][len] != -1) return dp[idx][len];

    // not take this piece length
    ll notTake = rod_memo(idx - 1, len, price, dp);

    // take: use one piece of length (idx+1) if it fits, then remain same idx (unbounded)
    ll take = LLONG_MIN;
    int pieceLen = idx + 1;
    if (pieceLen <= len) {
        take = price[idx] + rod_memo(idx, len - pieceLen, price, dp);
    }

    return dp[idx][len] = max(notTake, take);
}

int main() {
    vector<int> price = {2, 5, 7, 8}; // price[0]=price for length1 =2, length2=5,...
    int N = 5; // rod length
    int n = price.size();
    vector<vector<ll>> dp(n, vector<ll>(N + 1, -1));
    cout << "Memoization: " << rod_memo(n - 1, N, price, dp) << '\n';
    return 0;
}
