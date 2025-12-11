#include <bits/stdc++.h>
using namespace std;
int main() {
    string a, b;
    if (!(cin >> a >> b)) return 0;
    int n = (int)a.size();
    int m = (int)b.size();
    // dp[i][j] = length of longest common suffix of a[0..i-1] and b[0..j-1]
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int bestLen = 0;
    int bestEndA = 0; // index in a where the best substring ends (1-based in dp sense)
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                if (dp[i][j] > bestLen) {
                    bestLen = dp[i][j];
                    bestEndA = i; // substring ends at a[i-1]
                }
            } else {
                dp[i][j] = 0; // no continuity if chars differ
            }
        }
    }
    // print length and the substring (if any)
    cout << bestLen << '\n';
    if (bestLen > 0) {
        cout << a.substr(bestEndA - bestLen, bestLen) << '\n';
    }
    return 0;
}
