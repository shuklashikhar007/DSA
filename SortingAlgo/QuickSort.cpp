#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i < j){
        while(arr[i] <= pivot && i <= high - 1) i++;
        while(arr[j] > pivot && j >= low + 1) j--;
        if(i < j) swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]); // do this finally to place the pivot element on it's correct index in the array.
    return j;
}

void quickSort(vector<int>& arr, int low, int high) {
    if(low < high){
        int pindex = partition(arr, low, high);
        quickSort(arr, low, pindex - 1);
        quickSort(arr, pindex + 1, high);
    }
}

int main(){
    vector<int> arr = {1, 3, 4, 5, 6, 7, 8, 9, 10, 2};
    quickSort(arr, 0, 9);

    for(int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
