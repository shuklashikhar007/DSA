// 2D_Vector_Reference.cpp
// Comprehensive Guide to 2D Vectors in C++

#include <iostream>
#include <vector>
#include <algorithm> // for sort
#include <numeric>   // for accumulate

using namespace std;

void printMatrix(const vector<vector<int>>& mat) {
    for (const auto& row : mat) {
        for (int val : row)
            cout << val << " ";
        cout << "\n";
    }
}

int main() {
    // 1. Declaration
    vector<vector<int>> v;  // Empty 2D vector

    // 2. Fixed size 2D vector with default value
    int rows = 3, cols = 4;
    vector<vector<int>> fixed(rows, vector<int>(cols, 0));

    // 3. Manual Initialization
    vector<vector<int>> manual = {
        {1, 2, 3},
        {4, 5, 6}
    };

    // 4. Jagged Vector (different column sizes)
    vector<vector<int>> jagged = {
        {1, 2},
        {3, 4, 5},
        {6}
    };

    // 5. Access & Modify Elements
    manual[1][2] = 10; // Change 6 to 10

    // 6. Add a new row
    manual.push_back({7, 8, 9});

    // 7. Add element to an existing row
    manual[0].push_back(100);

    // 8. Iteration - Range-based
    cout << "\nManual matrix using range-based loop:\n";
    for (const auto& row : manual) {
        for (int val : row)
            cout << val << " ";
        cout << "\n";
    }

    // 9. Iteration - Index-based
    cout << "\nManual matrix using index-based loop:\n";
    for (int i = 0; i < manual.size(); ++i) {
        for (int j = 0; j < manual[i].size(); ++j)
            cout << manual[i][j] << " ";
        cout << "\n";
    }

    // 10. Resizing
    vector<vector<int>> resizable;
    resizable.resize(5); // 5 rows
    for (int i = 0; i < 5; ++i) {
        resizable[i].resize(3); // 3 columns
    }

    // 11. Sorting rows
    vector<vector<int>> toSort = {
        {3, 1, 2},
        {9, 7, 5},
        {6, 8, 4}
    };

    for (auto& row : toSort)
        sort(row.begin(), row.end());

    // 12. Sort rows by size or sum
    sort(toSort.begin(), toSort.end(), [](const vector<int>& a, const vector<int>& b) {
        return accumulate(a.begin(), a.end(), 0) < accumulate(b.begin(), b.end(), 0);
    });

    // 13. Passing 2D vector to function
    cout << "\nSorted matrix:\n";
    printMatrix(toSort);

    // 14. Clearing a 2D vector
    toSort.clear(); // Empties all contents

    // 15. Simulating 2D vector using flat 1D vector
    int n = 3, m = 4;
    vector<int> flat(n * m, 0); // flat 1D vector
    flat[1 * m + 2] = 99;       // Access like 2D: flat[i * cols + j]

    cout << "\nSimulated 2D (flat vector):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cout << flat[i * m + j] << " ";
        cout << "\n";
    }

    // Summary of Notes:
    /*
     - 2D Vector: vector<vector<int>> v;
     - Dynamic: rows/columns can change in size
     - Memory: Non-contiguous rows, slower than raw arrays in some cases
     - Access: v[i][j], Modify: v[i][j] = x;
     - Add Row: v.push_back({a, b, c});
     - Add to Row: v[i].push_back(x);
     - Resize: v.resize(rows); v[i].resize(cols);
     - Sort: sort(v[i].begin(), v[i].end());
     - Pass to Function: void f(const vector<vector<int>>& v);
     - Clear: v.clear();
     - Flat 2D Sim: vector<int> flat(r * c); flat[i * c + j]
    */

    return 0;
}
