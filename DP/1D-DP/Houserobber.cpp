#include<bits/stdc++.h>
using namespace std;
long long solve(vector<int>&arr){
    int n = arr.size();
    long long prev = arr[0];
    long long prev2 = 0;

    for(int i = 1 ; i <n ; i++){
        long long pick = arr[i];
        if(i>1){
            pick += prev2;
        }
        long long nonpick = 0 + prev;
        long long cur = max(pick,nonpick);
        prev2 = prev;
        prev = cur;
    }
    return prev;
}
long long int robstreet(int n, vector<int>&arr){
    vector<int>arr1;
    vector<int>arr2;

    if(n==1){
        return arr[0];
    }
    for(int i=0;i<n;i++){
        if(i!= 0) arr1.push_back(arr[i]);
        if(i!=n-1) arr2.push_back(arr[i]);
    }

    long long ans1 = solve(arr1);
    long long ans2 = solve(arr2);

    return max(ans1,ans2);
}

int main(){
    vector<int>arr = {1,5,1,2,6};
    int n = arr.size();
    cout << robstreet(n,arr);

    return 0;
}