// superseq -> shortest string having both s1 and s2 present as subsequences
#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();

    // Step 1: Build LCS DP table
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Step 2: Build the SCS string using while loop
    string scs = "";
    int i = n, j = m;

    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {          // characters match → take once
            scs.push_back(a[i - 1]);
            i--, j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {  
            scs.push_back(a[i - 1]);        // move in direction of larger LCS
            i--;
        } 
        else {
            scs.push_back(b[j - 1]);
            j--;
        }
    }

    // Step 3: add remaining characters
    while (i > 0) scs.push_back(a[i - 1]), i--;
    while (j > 0) scs.push_back(b[j - 1]), j--;

    // Final result must be reversed
    reverse(scs.begin(), scs.end());

    cout << scs << endl;

    return 0;
}
