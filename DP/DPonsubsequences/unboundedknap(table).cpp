#include <bits/stdc++.h>
using namespace std;

int unbounded_tab_2d(const vector<int>& wt, const vector<int>& val, int W) {
    int n = wt.size();
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    // base row: using only item 0 (take many copies)
    for (int w = 0; w <= W; ++w) {
        dp[0][w] = (w / wt[0]) * val[0];
    }

    for (int i = 1; i < n; ++i) {
        for (int w = 0; w <= W; ++w) {
            int notTake = dp[i - 1][w];
            int take = INT_MIN;
            if (wt[i] <= w) take = val[i] + dp[i][w - wt[i]]; // note dp[i][...], unbounded
            dp[i][w] = max(notTake, take);
        }
    }

    return dp[n - 1][W];
}

int main() {
    vector<int> wt  = {2, 3, 5};
    vector<int> val = {15, 20, 50};
    int W = 7;
    cout << "2D Tabulation answer: " << unbounded_tab_2d(wt, val, W) << '\n';
    return 0;
}
