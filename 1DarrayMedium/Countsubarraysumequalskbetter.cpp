#include<bits/stdc++.h>
using namespace std;
int noofsubarray(vector<int> arr, int k, int n){
    int ans = 0;
    vector<int> prefix(n);
    map<int, int> mp;

    prefix[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];  
    }

    for (int i = 0; i < n; i++) {
        if (prefix[i] == k) {
            ans++;  
        }

        if (mp.find(prefix[i] - k) != mp.end()) {
            ans += mp[prefix[i] - k];  
        }

        mp[prefix[i]]++;  
    }

    return ans;
}

int main(){

    vector<int>arr = {3,4,7,2,-3,1,4,2};
    int n = arr.size();
    int k = 7; // we have to count the number of subarray's having sum equal to 7
    int ans = noofsubarray(arr,k,n);
    cout << ans ;


    return 0;
}