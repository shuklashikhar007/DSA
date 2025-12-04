// memoization approach for Unbounded knapsack 
// Unbounded knapsack or bounded mai diff hai that we can infinite supply of a particular article 
// jo hame churana hai
// so we can stand at a index and when we select a element we can keep on selecting it 

#include <bits/stdc++.h>
using namespace std;

int unbounded_memo(int idx, int cap, const vector<int>& wt, const vector<int>& val, vector<vector<int>>& dp) {
    if (cap == 0) return 0;
    if (idx == 0) {
        // we can take as many of item 0 as fit
        return (cap / wt[0]) * val[0];
    }
    if (dp[idx][cap] != -1) return dp[idx][cap];

    // not take this item
    int notTake = unbounded_memo(idx - 1, cap, wt, val, dp);

    // take this item (since unbounded, stay at same idx)
    int take = INT_MIN;
    if (wt[idx] <= cap) take = val[idx] + unbounded_memo(idx, cap - wt[idx], wt, val, dp);

    dp[idx][cap] = max(take, notTake);
    return dp[idx][cap];
}

int main() {
    vector<int> wt  = {2, 3, 5};
    vector<int> val = {15, 20, 50};
    int W = 7;
    int n = wt.size();

    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    int ans = unbounded_memo(n - 1, W, wt, val, dp);
    cout << "Memoization answer: " << ans << '\n'; // example output
    return 0;
}
