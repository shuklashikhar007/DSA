#include <bits/stdc++.h>
using namespace std;

int maxProfitTab(const vector<int>& arr, int K) {
    int n = arr.size();
    if(n == 0 || K == 0) return 0;

    // small optimization: if K >= n/2, treat as infinite transactions
    if(K >= n/2) {
        int profit = 0;
        for(int i = 1; i < n; ++i)
            if(arr[i] > arr[i-1]) profit += arr[i] - arr[i-1];
        return profit;
    }

    // dp[ind][buy][cap] = max profit from day ind..n-1 given buy-state and remaining cap
    vector<vector<vector<int>>> dp(n+1,
        vector<vector<int>>(2, vector<int>(K+1, 0)));

    // base: dp[n][*][*] = 0 (already set)

    for(int ind = n-1; ind >= 0; --ind){
        for(int buy = 0; buy <= 1; ++buy){
            for(int cap = 0; cap <= K; ++cap){
                int profit = 0;
                if(buy){
                    // either buy now (pay price) and go to hold state (buy=0)
                    int take = -arr[ind] + dp[ind+1][0][cap];
                    // or skip
                    int skip = dp[ind+1][1][cap];
                    profit = max(take, skip);
                } else {
                    // if cap == 0 we cannot complete any more transactions (no sell allowed)
                    if(cap > 0){
                        int sell = arr[ind] + dp[ind+1][1][cap-1]; // sell now -> cap-1
                        int skip = dp[ind+1][0][cap];            // keep holding
                        profit = max(sell, skip);
                    } else {
                        // no transactions left: cannot sell => must skip (profit from future)
                        profit = dp[ind+1][0][cap];
                    }
                }
                dp[ind][buy][cap] = profit;
            }
        }
    }
    return dp[0][1][K]; // start at day 0 with ability to buy and K transactions allowed
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    if(!(cin >> n >> k)) return 0;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) cin >> arr[i];
    cout << maxProfitTab(arr, k) << '\n';
    return 0;
}
