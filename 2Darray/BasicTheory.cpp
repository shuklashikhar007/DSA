#include <iostream>
#include <algorithm>
using namespace std;
//Not done by now to be done later.
// Function to print 2D array
void printArray(int arr[][4], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 4; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

int main() {
    const int rows = 3, cols = 4;
    int arr[rows][cols];

    // Input
    cout << "Enter elements for 3x4 matrix:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> arr[i][j];

    // Output
    cout << "\nMatrix:\n";
    printArray(arr, rows);

    // Sort each row
    for (int i = 0; i < rows; i++)
        sort(arr[i], arr[i] + cols);

    cout << "\nMatrix after sorting each row:\n";
    printArray(arr, rows);

    return 0;
}

