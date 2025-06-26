#include <iostream>
using namespace std;

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];       // The element to insert
        int j = i - 1;
        // Move larger elements one step to the right
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  
            j--;
        }
        arr[j + 1] = key;  // Insert the element
    }
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main() {
    int numbers[] = {9, 7, 4, 1, 3};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    cout << "Before sorting:\n";
    printArray(numbers, n);

    insertionSort(numbers, n);

    cout << "After sorting:\n";
    printArray(numbers, n);

    return 0;
}
