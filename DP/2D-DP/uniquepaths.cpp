#include <bits/stdc++.h>
using namespace std;
int find(int i, int j, vector<vector<int>> &dp) {
    // Base case: top-left cell
    if (i == 0 && j == 0) return 1;
    // If indices go out of grid
    if (i < 0 || j < 0) return 0;
    // If already computed
    if (dp[i][j] != -1) return dp[i][j];
    // Move up and left
    int up = find(i - 1, j, dp);
    int left = find(i, j - 1, dp);
    return dp[i][j] = up + left;
}
int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> dp(m, vector<int>(n, -1));
    // Call for the bottom-right cell (m-1, n-1)
    int ans = find(m - 1, n - 1, dp);
    cout << ans << endl;
    return 0;
}
