#include <iostream>
using namespace std;

int findPivot(int arr[], int n) {
    int s = 0;
    int e = n - 1;

    while (s <= e) {
        // If the array is already sorted
        if (arr[s] <= arr[e]) return e;

        int mid = s + (e - s) / 2;

        // Check if mid is pivot
        if (mid < n - 1 && arr[mid] > arr[mid + 1]) {
            return mid;
        }

        // Check if mid-1 is pivot
        if (mid > 0 && arr[mid] < arr[mid - 1]) {
            return mid - 1;
        }

        // Decide which half to choose
        if (arr[mid] >= arr[s]) {
            s = mid + 1; // pivot is on the right
        } else {
            e = mid - 1; // pivot is on the left
        }
    }

    return -1; // Not found
}

int main() {
    int arr[] = {7, 9, 1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int index = findPivot(arr, n);
    cout << "Pivot point (max element) is at index: " << index << ", value: " << arr[index] << endl;
    return 0;
}
