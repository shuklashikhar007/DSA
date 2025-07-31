#include<bits/stdc++.h>
using namespace std;
void merge(vector<int> &arr, int low, int mid , int high){
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    // agar end mai left half ke elements bach gaye to 
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }
    // transfer all elements from temporary to original array 
    for(int i = low ; i <= high; i++){
        arr[i] = temp[i-low];
    }
}
int countpairs(vector<int> &arr, int low, int mid , int high){
    int right = mid + 1;
    int cnt = 0;
    for(int i=low; i<= mid;i++){
        while(right <= high && arr[i] > 2* arr[right] ){
            right++;
        }
        cnt += (right - (mid+1));
    }
    return cnt;
}
int mergesort(vector<int> &arr, int low , int high){
    int cnt = 0;
    if(low >= high){
        return cnt;
    }
    int mid = (low + high)/2;
    cnt += mergesort(arr,low,mid);
    cnt += mergesort(arr,mid+1,high);
    cnt += countpairs(arr,low,mid,high);
    merge(arr,low,mid,high);
    return cnt;

}
int team(vector<int> &skill,int n){
    return mergesort(skill,0,n-1);
}
int main(){
    vector<int> a = {4,1,2,3,1};
    int n = 5;
    int cnt = team(a,n);
    cout << "The number of reverse pairs are : " << cnt << endl;
    return 0;
}