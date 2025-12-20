#include<bits/stdc++.h>
using namespace std;
int mincost(vector<int>&ropes){
    priority_queue<int, vector<int>, greater<int> > pq; // mih heap
    for(int x : ropes) pq.push(x);
    int cost = 0;
    while (pq.size() >1 )
    {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        cost += (a+b);
        pq.push(a+b);
    }
    return cost;
}
int main(){
    // yaha cost min tab ayegi jab we make the complete rope by joining the smallest ropes together 
    // to isliye min heap use karege
    return 0;
}