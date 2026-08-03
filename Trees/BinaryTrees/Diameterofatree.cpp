#include<bits/stdc++.h>
using namespace std;
pair<int,int> bfs(int src, vector<vector<int>>&adj){
    int n = adj.size();
    vector<int>dist(n,-1);
    queue<int>q;
    q.push(src);
    dist[src] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v : adj[u]){
            if(dist[v] == -1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    int far = src;
    for(int i=0;i<n;i++){
        if(dist[i] > dist[far]){
            far = i;
        }
    }
    return {far, dist[far]};
}
int dia(vector<vector<int>>&adj){
    auto p1 = bfs(0,adj);
    auto p2 = bfs(p1.first,adj);
    return p2.second;
}
int main(){

    return 0;
}