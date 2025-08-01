// condition for a pair of elements to form a pair of inversions ->
// if i < j then A[i] > A[j];

#include<bits/stdc++.h>
using namespace std;
int merge(vector<int> &arr, int low, int mid,int high){
    vector<int>temp;
    int left = low; // starting index of left half of array 
    int right = mid + 1; // starting index of right array 

    int cnt = 0; //  variable to count number of inversions
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            cnt += (mid - left + 1); // yoki array sorted hai to yaha se leke iske agge tak sare i us particular j ke sath pair banayege
            // since all element in first half after this i will be greater than this particular arr[j]
            right++;
        }
    }
    return cnt;
}
int mergeSort(vector<int> &arr, int low , int high){
    int cnt = 0;
    if(low>=high){
        return cnt;
    }
    int mid = (low+high)/2;
    cnt += mergeSort(arr,low,high); // left half arrray ka 
    cnt += mergeSort(arr,mid+1,high);
    cnt += merge(arr,low,mid,high);
    return cnt;
}
int numberofinversions(vector<int>&a , int n){
    return mergeSort(a,0,n-1);
}
int main(){

    vector<int> a = {5,4,3,2,1};
    int n = 5;
    int cnt = numberofinversions(a,n);
    cout << "The number of inversions are : " << cnt << endl;

    return 0;
}