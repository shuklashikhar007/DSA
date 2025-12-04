#include <bits/stdc++.h>
using namespace std;

int findcoins(int ind, int target, vector<int>& arr, vector<vector<int>> &dp) {
    // base cases
    if (ind == 0) {
        if (target % arr[0] == 0) return target / arr[0];
        else return INT_MAX; 
    }
    if (dp[ind][target] != -1) return dp[ind][target];

    // not take
    int nottake = findcoins(ind - 1, target, arr, dp);

    // take (unbounded - can take same coin again)
    int take = INT_MAX;
    if (arr[ind] <= target) {
        int sub = findcoins(ind, target - arr[ind], arr, dp);
        if (sub != INT_MAX) take = 1 + sub; // only add if sub is valid
    }

    return dp[ind][target] = min(take, nottake);
}

int coins(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    int noofcoins = findcoins(n - 1, target, arr, dp);
    if (noofcoins == INT_MAX) return -1; // no solution
    return noofcoins;
}

int main() {
    vector<int> arr = {1,2,3};
    int target = 8;
    int ans = coins(arr, target);
    cout << ans << endl; // prints 3 (3+3+2 or other), or -1 if impossible
    return 0;
}
