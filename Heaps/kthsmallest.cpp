#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    priority_queue<int> pq; // max heap
    for(int x : arr){
        pq.push(x);
        if(pq.size() > k){
            pq.pop();
        }
    }
    cout <<  pq.top();
    return 0;
}