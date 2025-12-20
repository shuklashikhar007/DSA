#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    priority_queue<int, vector<int>, greater<int>> minh;
    for(int i=0;i<n;i++){
        minh.push(arr[i]);
        if(minh.size() > k){
            minh.pop();
        }
    }
    cout <<  minh.top();
    return 0;
}