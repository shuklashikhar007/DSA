// tabulation approach for the same problem 
#include <bits/stdc++.h>
using namespace std;
int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    // Base case: last row is same as matrix last row
    for (int j = 0; j < m; j++) {
        dp[n - 1][j] = matrix[n - 1][j];
    }

    // Bottom-up DP
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            int down = dp[i + 1][j];
            int downleft = (j > 0) ? dp[i + 1][j - 1] : INT_MAX;
            int downright = (j < m - 1) ? dp[i + 1][j + 1] : INT_MAX;

            dp[i][j] = matrix[i][j] + min({down, downleft, downright});
        }
    }

    // Minimum path sum from top row
    return *min_element(dp[0].begin(), dp[0].end());
}

int main() {
    vector<vector<int>> matrix = {
        {1, 4, 3, 1},
        {2, 3, -1, -1},
        {1, 1, -1, 8}
    };

    cout << "Minimum Falling Path Sum: " << minFallingPathSum(matrix) << endl;
    return 0;
}
