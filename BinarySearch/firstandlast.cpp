#include <iostream>
using namespace std;

// since we have to search using binary search then the array will be by default sorted, so when we search for the first occurence we search along the left 
// and when we search for the second occur we searcb in the right side.
int firstOccurrence(int arr[], int size, int key) {
    int s = 0, e = size - 1;
    int ans = -1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] == key) {
            ans = mid;
            e = mid - 1; 
        }
        else if (key > arr[mid]) {
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
        
    }
    
    return ans;
}

int lastOccurrence(int arr[], int size, int key) {
    int s = 0, e = size - 1;
    int ans = -1;
   
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] == key) {
            ans = mid;
            s = mid + 1;  
        }
        else if (key > arr[mid]) {
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
        
    }
    
    return ans;
}

int main() {
    int arr[7] = {1, 2, 3, 3, 3, 4, 5};
    int key = 3;

    int first = firstOccurrence(arr, 7, key);
    int last = lastOccurrence(arr, 7, key);

    if (first == -1) {
        cout << key << " is not present in the array." << endl;
    } else {
        cout << key << " is present from index " << first << " to " << last << "." << endl;
    }

    return 0;
}
