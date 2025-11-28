#include<bits/stdc++.h>
using namespace std;
int f(int ind, vector<int>& arr, vector<int>& dp) {
    if (ind < 0) return 0;
    if (ind == 0) return arr[0];

    if (dp[ind] != -1) return dp[ind];

    int pick = arr[ind] + f(ind - 2, arr, dp);
    int nonPick = f(ind - 1, arr, dp);

    return dp[ind] = max(pick, nonPick);
}

int solve(int n, vector<int>& arr) {
    vector<int> dp(n, -1);
    return f(n - 1, arr, dp);
}

int main() {
    vector<int> arr {2,1,4,9};
    cout << solve(arr.size(), arr);
    return 0;
}