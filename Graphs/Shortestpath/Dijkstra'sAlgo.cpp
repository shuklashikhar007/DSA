#include<bits/stdc++.h>
using namespace std;
vector<int> dijkstra(int V, vector<vector<int>> &egdes, int src){
    vector<pair<int,int>> adj[V];
    for(auto &e : egdes){
        int u = e[0];
        int v = e[1];
        int w = e[2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int>dist(V, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq; // min heap
    pq.push({0,src}); // starting node enter kardo pehle
    while (!pq.empty())
    {
        int d = pq.top().first; // pq mai topmost element ka source se shortest distance
        int node = pq.top().second; // current node 
        pq.pop();
        if(d > dist[node]) continue;
        for(auto it : adj[node]){
            
        }       
    }

}
int main(){
    int V = 5;
    vector<vector<int>> edges = {
        {0,1,2},
        {0,2,4},
        {1,2,1},
        {1,3,7},
        {2,4,3},
        {3,4,1}
    };
    int src = 0;
    vector<int>ans = dijkstra(V,edges, src);
    for(int i=0;i<V;i++){
        cout << ans[i] << " ";
    }
    return 0;
}