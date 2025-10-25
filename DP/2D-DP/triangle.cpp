#include <bits/stdc++.h>
using namespace std;

// Class to solve the triangle minimum path sum
class Solution {
public:
    // Function to compute the minimum path sum using tabulation
    int minimumPathSum(vector<vector<int>> &triangle, int n) {
        // Create a 2D dp array to store intermediate results
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Initialize the last row of dp with triangle values
        for (int j = 0; j < n; j++) {
            dp[n - 1][j] = triangle[n - 1][j];
        }

        // Traverse from second-last row to the top
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                // Calculate sum from down and diagonal paths
                int down = triangle[i][j] + dp[i + 1][j];
                int diag = triangle[i][j] + dp[i + 1][j + 1];

                // Store the minimum of the two paths
                dp[i][j] = min(down, diag);
            }
        }

        // Return the minimum path sum from top
        return dp[0][0];
    }
};

// Main function to run the code
int main() {
    // Define the triangle
    vector<vector<int>> triangle{
        {1},
        {2, 3},
        {3, 6, 7},
        {8, 9, 6, 10}
    };

    // Get the number of rows
    int n = triangle.size();

    // Create object of the Solution class
    Solution solver;

    // Print the result
    cout << solver.minimumPathSum(triangle, n);

    return 0;
}