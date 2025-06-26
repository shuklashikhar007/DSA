#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size) {
    for (int pass = 0; pass < size - 1; pass++) {
        for (int i = 0; i < size - 1 - pass; i++) {
            if (arr[i] > arr[i + 1]) {
                // Swap using a temporary variable
                swap(arr[i],arr[i+1]);
            }
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int numbers[] = {5, 3, 1, 4, 2};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    cout << "Before sorting:\n";
    printArray(numbers, n);

    bubbleSort(numbers, n);

    cout << "After sorting:\n";
    printArray(numbers, n);

    return 0;
}
