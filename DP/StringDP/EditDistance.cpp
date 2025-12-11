#include <bits/stdc++.h>
using namespace std;
// f(i, j) = min operations to convert a[0..i-1] -> b[0..j-1]
// i in [0..n], j in [0..m]
int f(const string &a, const string &b, int i, int j, vector<vector<int>> &dp) {
    if (i == 0) return j; // need j inserts
    if (j == 0) return i; // need i deletes
    if (dp[i][j] != -1) return dp[i][j];
    if (a[i - 1] == b[j - 1]) {
        dp[i][j] = f(a, b, i - 1, j - 1, dp);
    } else {
        int insertOp  = 1 + f(a, b, i,     j - 1, dp); // insert b[j-1] into a -> reduces j
        int deleteOp  = 1 + f(a, b, i - 1, j,     dp); // delete a[i-1] -> reduces i
        int replaceOp = 1 + f(a, b, i - 1, j - 1, dp); // replace a[i-1] with b[j-1]
        dp[i][j] = min({insertOp, deleteOp, replaceOp});
    }
    return dp[i][j];
}
int edit_distance_memo(const string &a, const string &b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return f(a, b, n, m, dp);
}
int main() {
    string a, b;
    if (!(cin >> a >> b)) return 0;
    cout << edit_distance_memo(a, b) << '\n';
    return 0;
}
