#include <iostream>
#include <vector>
using namespace std;

void countSort(int arr[], int n) {
    int maxVal = *max_element(arr, arr + n);
    vector<int> count(maxVal + 1, 0);

    // Count frequency
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // Build sorted array
    int index = 0;
    for (int i = 0; i <= maxVal; i++) {
        while (count[i]--) {
            arr[index++] = i;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting:\n";
    printArray(arr, n);

    countSort(arr, n);

    cout << "After sorting:\n";
    printArray(arr, n);

    return 0;
}
