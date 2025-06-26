#include<iostream>
using namespace std;
// same question using binary search
int peakIndexInMountainArray ( int arr[] , int n){
    int s = 0;
    int e = n - 1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<e){
        if(arr[mid] < arr[mid+1]){
            s = mid + 1;
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return mid;
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