#include <iostream>
#include <vector>
using namespace std;

int searchInRotatedSortedArray(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
            return mid;

        // Check if left half is sorted
        if (arr[low] <= arr[mid]) {
            // Check if target lies in left half
            if (arr[low] <= target && target < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        // Right half must be sorted
        else {
            // Check if target lies in right half
            if (arr[mid] < target && target <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    return -1; // Target not found
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2}; // Rotated sorted array
    int target = 0;

    int index = searchInRotatedSortedArray(arr, target);

    if (index != -1)
        cout << "Element " << target << " found at index " << index << endl;
    else
        cout << "Element " << target << " not found in the array" << endl;

    return 0;
}