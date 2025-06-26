#include<iostream>
using namespace std;
int peakIndexInMountainArray(int arr[], int n){
    for(int i = 1; i < n - 1; i++) {
        if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) { // id the elment is bigger than it's prev element and greater than the one that is ahead it is surely the peak !
            return i;
        }
    }
    return -1;// if not found
}
int main(){
   int arr[7] = {1,3,5,7,6,4,2};
   int ans = peakIndexInMountainArray(arr,7);
   if(ans == -1){
        cout << "No peak !! " << endl;
   }
   cout << "peak present at index no : " << ans << endl;    
    return 0;
}