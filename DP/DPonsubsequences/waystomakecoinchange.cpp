// memoization approach 
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll ways_memo(int idx, int target, const vector<int>& coins, vector<vector<ll>>& dp) {
    if (target == 0) return 1;           // one way: pick nothing
    if (idx == 0) {
        // only coin 0 available: can we form target using repeated coin[0]?
        return (target % coins[0] == 0) ? 1 : 0;
    }
    if (dp[idx][target] != -1) return dp[idx][target];

    // not take coin idx
    ll notTake = ways_memo(idx - 1, target, coins, dp);

    // take coin idx (if fits)
    ll take = 0;
    if (coins[idx] <= target) take = ways_memo(idx, target - coins[idx], coins, dp);

    return dp[idx][target] = notTake + take;
}

int main() {
    vector<int> coins = {1, 2, 3};
    int target = 4;
    int n = coins.size();
    vector<vector<ll>> dp(n, vector<ll>(target + 1, -1));
    cout << ways_memo(n - 1, target, coins, dp) << '\n'; // expected 4
    // ways: {1+1+1+1, 1+1+2, 2+2, 1+3}
    return 0;
}
