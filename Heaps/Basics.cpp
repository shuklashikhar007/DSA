#include<bits/stdc++.h>
using namespace std;
struct compare{
    bool operator()(const pair<int,pair<int,int>>&a, const pair<int,pair<int,int>>&b) const {
        if(a.first != b.first)
            return a.first < b.first;   // smaller "first" = higher priority (max-heap on first)
        return a.second.first < b.second.first;
    }
};
int main(){
    // max heap
    priority_queue<int> maxHeap;
    // min heap
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> minHeap;
    // custom pq
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, compare> customPQ;
    return 0;
}