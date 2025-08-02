#include <iostream>
#include <vector>
using namespace std;

// Function to find the first occurrence of target
int firstOccurrence(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            result = mid;     // potential answer
            high = mid - 1;   // look in left half
        }
        else if (arr[mid] < target) {
            low = mid + 1;    // search right half
        }
        else {
            high = mid - 1;   // search left half
        }
    }

    return result;
}

// Function to find the last occurrence of target
int lastOccurrence(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            result = mid;     // potential answer
            low = mid + 1;    // look in right half
        }
        else if (arr[mid] < target) {
            low = mid + 1;    // search right half
        }
        else {
            high = mid - 1;   // search left half
        }
    }

    return result;
}

int main() {
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5};  // sorted array
    int target = 2;

    int first = firstOccurrence(arr, target);
    int last = lastOccurrence(arr, target);

    if (first != -1 && last != -1) {
        cout << "First occurrence of " << target << " is at index " << first << endl;
        cout << "Last occurrence of " << target << " is at index " << last << endl;
    } else {
        cout << "Element not found." << endl;
    }
    cout << "The number of occurences of the target element is  : " << (last - first) + 1 << endl;
    return 0;
}
