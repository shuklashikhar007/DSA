#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll ways_tab_2d(const vector<int>& coins, int target) {
    int n = coins.size();
    vector<vector<ll>> dp(n, vector<ll>(target + 1, 0));

    // base: there is 1 way to make sum 0 with any set of coins
    for (int i = 0; i < n; ++i) dp[i][0] = 1;

    // fill base row: using only coin 0
    for (int t = 0; t <= target; ++t) {
        dp[0][t] = (t % coins[0] == 0) ? 1 : 0;
    }

    for (int i = 1; i < n; ++i) {
        for (int t = 1; t <= target; ++t) {
            ll notTake = dp[i - 1][t];
            ll take = 0;
            if (coins[i] <= t) take = dp[i][t - coins[i]]; // same row, unbounded
            dp[i][t] = notTake + take;
        }
    }
    return dp[n - 1][target];
}

int main() {
    vector<int> coins = {1, 2, 3};
    int target = 4;
    cout << ways_tab_2d(coins, target) << '\n'; // expected 4
    return 0;
}
