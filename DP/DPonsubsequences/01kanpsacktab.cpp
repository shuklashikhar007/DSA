#include <bits/stdc++.h>
using namespace std;

int knapsack(int W, vector<int>& wt, vector<int>& val) {
    int n = wt.size();

    // dp[i][w] = max value using first i items and capacity w
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build table row-by-row
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {

            int notTake = dp[i - 1][w];   // not pick ith item

            int take = INT_MIN;
            if (wt[i - 1] <= w) {
                take = val[i - 1] + dp[i - 1][w - wt[i - 1]];  // pick ith item
            }

            dp[i][w] = max(take, notTake);
        }
    }

    return dp[n][W];
}

int main() {
    vector<int> wt = {3, 2, 4, 5};
    vector<int> val = {4, 3, 5, 6};
    int W = 8;

    cout << knapsack(W, wt, val) << endl;  // Output: 11
    return 0;
}
