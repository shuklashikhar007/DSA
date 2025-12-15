// basic recursive approach to Partition DP problem 
#include<bits/stdc++.h>
using namespace std;
int MCM(vector<int>&arr, int i, int j){
    if(i==j) return 0; // base case agar ek hi matrix present hai to
    int mincost = INT_MAX;
    for(int k=i;k<j;k++){
        // i se k tak ke matrix ki cost
        int cost1 = MCM(arr,i,k);
        int cost2 = MCM(arr,k+1,j);
        int costmultiply = arr[i-1]*arr[k]*arr[j];
        int total = cost1 + cost2 + costmultiply;
        mincost = min(mincost, total); 
    }
    return mincost;
}
int main(){
    vector<int>arr = {40,20,30,10,30};
    int n = arr.size();
    cout << "MIN number of multiplications : " << MCM(arr,1,n-1) << endl;
    return 0;
}