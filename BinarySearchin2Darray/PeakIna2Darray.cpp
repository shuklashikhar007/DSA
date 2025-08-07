#include <iostream>
#include <vector>
using namespace std;
// to store multiple peaks make a answer array and store the answers in that vector.
// Function to find a peak element in a 2D matrix
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        
        int left = 0, right = cols - 1;

        // Binary search on columns
        while (left <= right) {
            int midCol = left + (right - left) / 2;

            // Find the max element in midCol
            int maxRow = 0;
            for (int i = 0; i < rows; ++i) {
                if (mat[i][midCol] > mat[maxRow][midCol]) {
                    maxRow = i;
                }
            }

            // Get the neighbors of mat[maxRow][midCol]
            int leftNeighbor = (midCol > 0) ? mat[maxRow][midCol - 1] : -1;
            int rightNeighbor = (midCol < cols - 1) ? mat[maxRow][midCol + 1] : -1;

            // If current element is greater than both neighbors, it's a peak
            if (mat[maxRow][midCol] > leftNeighbor && mat[maxRow][midCol] > rightNeighbor) {
                return {maxRow, midCol};
            }
            // Move to the side with the greater neighbor
            else if (leftNeighbor > mat[maxRow][midCol]) {
                right = midCol - 1;
            } else {
                left = midCol + 1;
            }
        }

        return {-1, -1}; // Should never reach here due to problem constraints
    }
};

int main() {
    Solution sol;

    // Sample input matrix
    vector<vector<int>> mat = {
        {10, 20, 15},
        {21, 30, 14},
        {7, 16, 32}
    };

    // Find a peak
    vector<int> peak = sol.findPeakGrid(mat);

    // Output the peak coordinates
    cout << "Peak found at: [" << peak[0] << ", " << peak[1] << "]" << endl;
    cout << "Peak value: " << mat[peak[0]][peak[1]] << endl;

    return 0;
}
