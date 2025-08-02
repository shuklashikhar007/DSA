#include<bits/stdc++.h>
using namespace std;
int single(vector<int> &arr){
    int n = arr.size();
    if(n==1){
        return arr[0];
    }
    if(arr[0] != arr[1]){
        return arr[0];
    }
    if(arr[n-1] != arr[n-2]){
        return arr[n-1];
    }

    int low = 1;
    int high = n - 2;
    while(low <= high){
        int mid = (low+high)/2;
        // code for single element found
        if(arr[mid] != arr[mid+1] && arr[mid] != arr[mid-1]){
            return arr[mid];
        }
        if(mid%2 == 1 && arr[mid] == arr[mid-1] || mid%2 == 0 && arr[mid] == arr[mid+1]){
            // we are in the left half eliminate the left half
            low = mid + 1;
        }
        else{
            // eliminate the right half
            high = mid - 1;
        }
    }
    return -1;
}
int main(){

    vector<int> arr= {1,1,2,2,3,3,4,5,5,6,6};
    int ans = single(arr);
    cout << "The single element is : " << ans << endl;

    return 0;
}