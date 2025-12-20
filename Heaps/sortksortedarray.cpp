#include<bits/stdc++.h>
using namespace std;
vector<int> sortKarr(vector<int>&a, int k){
   priority_queue<int, vector<int>, greater<int>> minHeap;
    int index = 0;
    for (int i = 0; i <= k && i < a.size(); i++) {
        minHeap.push(a[i]);
    }
    for (int i = k + 1; i < a.size(); i++) {
        a[index++] = minHeap.top();
        minHeap.pop();
        minHeap.push(a[i]);
    }
    while (!minHeap.empty()) {
        a[index++] = minHeap.top();
        minHeap.pop();
    }
    return a;
}
int main(){
    int n,k;
    cin >> n >> k;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    vector<int>b = sortKarr(arr,k);
    for(int i=0;i<n;i++){
        cout << b[i] << " ";
    }
    return 0;
}