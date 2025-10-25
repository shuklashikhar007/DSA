#include<bits/stdc++.h>
using namespace std;
int minFallingPathSum(vector<vector<int>>&matrix){
    int n  = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m,-1));
    // tabulation matrix of same size as original matrix bana lege

    for(int j = 0; j < m ; j++){
        dp[n-1][j] = matrix[n-1][j];
    }

    for(int i=n-2;i>=0;i--){
        for(int j=0;j<m;j++){
            int down = dp[i+1][j];
            int downleft = dp[i+1][j-1];
            int downright = dp[i+1][j+1];

            dp[i][j] = matrix[i][j] + min({down,downleft,downright});
        }
    }

    int minsum = *min_element(dp[0].begin(),dp[0].end());
    return minsum;
}
int main(){
    vector<vector<int>> matrix = {
        {1, 4, 3, 1},
        {2, 3, -1, -1},
        {1, 1, -1, 8}
    };
    cout << "Minimum Falling Path Sum: " << minFallingPathSum(matrix) << endl;
    return 0;
}