#include<bits/stdc++.h>
using namespace std;
vector<int>topk(vector<int>&a, int k){
    unordered_map<int,int>mpp;
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
    // min heap wali pq 
    for(auto it : mpp){
        pq.push({it.second, it.first});
        while (pq.size() > k)
        {
            pq.pop();
        }
    }
    vector<int>ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
   return ans;
}
int main(){

    return 0;
}