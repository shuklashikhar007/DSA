#include<bits/stdc++.h>
using namespace std;
bool possible(vector<int> &arr, int day, int m, int k){
    int n = arr.size();
    int cnt = 0;
    int noofB = 0;
    for(int i=0;i<n;i++){
        if(arr[i] <= day){
            cnt++;
        }
        else{
            noofB += (cnt/k);
            cnt = 0;
        }
    }
    noofB += (cnt/k);
    return noofB >= m;
}
int rose(vector<int> arr, int k , int m ){
    long long val = m * 111 * k * 111;
    int n = arr.size();
    if(val > n){
        return -1; // impossible case 
    }
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        mini = min(mini,arr[i]);
        maxi = max(maxi,arr[i]);
    }
    // pehle find the largest value in array and smallest in the array 
    // this will be the search space of our binary search algo 
    int low = mini;
    int high = maxi;
    while(low <= high){
        int mid = (low + high)/2;
        if(possible(arr,mid,m,k)){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}
int main(){
    vector<int> arr = { 7 , 7 , 7 , 7 ,13,11,12, 7};
    int k = 3;
    int m = 2;
    int ans = rose(arr,k,m);
    if(ans == -1){
        cout << "Nahi ban payege m bouquets" << endl;
    }
    else{
        cout << "We can make m bouquets on day " << ans << endl;
    }

    return 0;
}