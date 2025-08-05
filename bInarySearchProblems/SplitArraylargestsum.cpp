#include<bits/stdc++.h>
using namespace std;
bool ispossible(vector<int> &arr, int k , int mid){
    int part = 1;
    int sum = 0;
    for(int i=0 ; i< arr.size(); i++){
        if(sum + arr[i] <= mid){
            sum += arr[i];
        }
        else{
            part++;
            if(part > k || arr[i] > mid){
                return false;
            }
        }
        sum = arr[i]; // place value of sum on next value of nums 
    }
    return true; // agar pura loop complete without any problem return true;

}
int splitarray(vector<int> &arr, int k){
    int s = *max_element(arr.begin(),arr.end());
    int e = accumulate(arr.begin(),arr.end(),0);
    // accumulate is a inline function to get the sum of all the elements 
    // of an array 
    int ans = e;
    while(s <= e){
        int mid = s + (e-s)/2;
        if(ispossible(arr,k,mid)){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    return ans;
}
int main(){

    vector<int> arr = {7,2,5,10,8};
   int ans =  splitarray(arr,2);
   

    return 0;
}