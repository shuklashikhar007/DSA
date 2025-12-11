#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    if (!(cin >> a >> b)) return 0;

    int n = (int)a.length();
    int m = (int)b.length();

    // dp[i][j] = LCS length of a[0..i-1] and b[0..j-1]
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // fill table (i and j run from 1..n and 1..m)
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i - 1] == b[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // length of LCS
    int len = dp[n][m];
    string lcs;
    lcs.resize(len);              // allocate space

    // backtrack to build the LCS (from dp[n][m] to dp[0][0])
    int i = n, j = m, idx = len - 1;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            lcs[idx] = a[i - 1];
            --i; --j; --idx;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }

    cout << lcs << '\n';
    return 0;
}
