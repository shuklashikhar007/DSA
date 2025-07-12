#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//Not done by now to be done later.
// Function to print 2D array
void printArray(int arr[][4], int rows) { // it's necessary to specify the column size but it's not mandatory to specify the row size
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
   // for (int i = 0; i < rows; i++)
     //   sort(arr[i], arr[i] + cols);
    // if i want to sort the columns as well

    for(int i=0;i<cols;i++){
        sort(arr[i],arr[i] + rows);
    }

    cout << "\nMatrix after sorting each cols:\n";
    printArray(arr, rows);
    
  

    return 0;
}

