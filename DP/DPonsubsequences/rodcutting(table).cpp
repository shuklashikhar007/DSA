#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll rod_tab_2d(const vector<int>& price, int N) {
    int n = price.size();
    // dp[i][len] = max revenue using piece lengths 1..(i+1) for rod length = len
    vector<vector<ll>> dp(n, vector<ll>(N + 1, 0));

    // base: using only piece length 1 (idx 0)
    for (int len = 0; len <= N; ++len) {
        dp[0][len] = (ll)len * price[0];
    }

    for (int i = 1; i < n; ++i) {
        int pieceLen = i + 1;
        for (int len = 0; len <= N; ++len) {
            ll notTake = dp[i - 1][len];
            ll take = LLONG_MIN;
            if (pieceLen <= len) take = price[i] + dp[i][len - pieceLen]; // same row => unbounded
            dp[i][len] = max(notTake, take);
        }
    }
    return dp[n - 1][N];
}

int main() {
    vector<int> price = {2, 5, 7, 8}; // prices for lengths 1..4
    int N = 5;
    cout << "2D Tabulation: " << rod_tab_2d(price, N) << '\n';
    return 0;
}
