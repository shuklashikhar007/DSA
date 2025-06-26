#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// to be done and understood later 
int main() {
    int rows = 3, cols = 4;

    // Declare and initialize 2D vector with 0s
    vector<vector<int>> mat(rows, vector<int>(cols, 0));

    // Input
    cout << "Enter elements for 3x4 matrix:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> mat[i][j];

    // Output
    cout << "\nMatrix:\n";
    for (const auto &row : mat) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }

    // Sort each row
    for (auto &row : mat)
        sort(row.begin(), row.end());

    cout << "\nMatrix after sorting each row:\n";
    for (const auto &row : mat) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }

    // Sort entire 2D vector by first column
    sort(mat.begin(), mat.end(), [](const vector<int> &a, const vector<int> &b) {
        return a[0] < b[0];
    });

    cout << "\nMatrix after sorting rows by first column:\n";
    for (const auto &row : mat) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
