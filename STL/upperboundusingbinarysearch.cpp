#include<bits/stdc++.h>
using namespace std;
// upper bound hota hai wo pehla index i jaha pe arr[i] > target
int upper(vector<int>arr, int target){
    int l = 0;
    int h = arr.size() -1;
    while(l < h){
        int mid = l + (h-l)/2;
        if(arr[mid] > target){
            // arr[i] bhi potential answer hai
            h = mid;
        } 
        else{ // matlab arr[i] <= target
            l = mid + 1;
        }
    }
    return l;
}
int main(){
    int t;
    cin  >> t;
    while (t--)
    {
       int n,k;
       cin >> n >> k;
       vector<int>arr(n);
       for(int i=0;i<n;i++) cin >> arr[i];
       int ans = upper(arr,k);
       cout << ans << endl;
    }
    return 0;
}
// upperbound using inbuilt
/*
int upper_bound_custom(vector<int>& v, int target) {
    int low = 0;
    int high = v.size();
    
    while (low < high) {
        int mid = low + (high - low) / 2;

        if (v[mid] <= target) {
            // mid value still <= target → we need to go right
            low = mid + 1;
        } else {
            // v[mid] > target → possible answer, go left
            high = mid;
        }
    }
    return low; // index of first element > target
}
*/