// Algo to find the wt sum of the minimum spanning tree of a graph
// MST is nothing but a tree in which all the nodes of the original graph are connected under the condition that
// all the edges connecting these nodes have their sum of weights a minimum 
#include<bits/stdc++.h>
using namespace std;
using dokapair = pair<int,int>;
class Solution{
    public:
    int MST(int V, vector<vector<pair<int,int>>>& adj){
        priority_queue<dokapair , vector<dokapair> , greater<dokapair>> pq;
        vector<int> vis(V,0);
        pq.push({0,0});
        int sum  = 0;
        // priority queue hamesa min wt wala node hi uthayegi 
        // har ham make sure karege ki pq mai wahi node dale jo vistied nahi hai pehle
        // only add it to pq if it is not visited
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;
            if( vis[node] == 1){
                continue; // ye node already visited hai
            }
            // MST mai add karne se pehle mark it visited
            vis[node] = 1;
            sum += wt;
            for(auto it : adj[node]){
    int adjnode = it.first;
    int edw = it.second;
    if(!vis[adjnode]){
        pq.push({edw , adjnode});
    }
}

        }
        return sum;
    }
};
int main(){

    return 0;
}