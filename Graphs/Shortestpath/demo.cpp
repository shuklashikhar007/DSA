/*
Weighted graph
No negative edges
Need shortest path

*/
/*
Comparison with Other Shortest Path Algorithms
Algorithm	Handles Negatives	Cycles	Time
BFS	        ❌	               ✅	O(V+E)
Topo + DP	✅	                ❌	O(V+E)
Dijkstra	❌	                ✅	O(E log V)
Bellman-Ford	✅	            ✅	O(VE)

*/
#include<bits/stdc++.h>
using namespace std;
vector<int> dijkstra(int V, vector<vector<int>> &egdes, int src){
    vector<pair<int,int>> adj[V];
    vector<int> parent(V+1);
    // parent arr for backtracking and printing the shortest possible path in this case
    for(int i=1;i<=V;i++){
        parent[i] = i;
    }
    for(auto &e : egdes){
        int u = e[0];
        int v = e[1];
        int w = e[2];
        // yaha pe undirected graph hai to dono push honge
        // btw ham ye algo directed mai bhi laga sakte hai
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
        
        for(auto it : adj[node]){
            // v -> neigh node ki value
            // w - us particular edge ka weight
            int v = it.first;
            int w = it.second;
            if(dist[node] + w < dist[v]){
                dist[v] = w + dist[node];
                pq.push({dist[v], v});
                parent[v] = node; // make a record entry of where we came from to this node in the shortest path case
            }
        }       
    }
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            dist[i] = -1;
    }
    return dist;
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