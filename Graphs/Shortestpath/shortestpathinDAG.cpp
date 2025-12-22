// a way to find the shortest path in Directed Acyclic graph from a source node
#include<bits/stdc++.h>
using namespace std;
void dfs(int node , vector<int>&vis,stack<int>&st , vector<pair<int,int>> adj[]){
    vis[node] = 1;
    for(auto it: adj[node]){
        int e = it.first;
        if(!vis[e]){
            dfs(e, vis, st, adj);
        }
    }
    st.push(node);
}
vector<int> toposort(int V, vector<pair<int,int>> adj[]){
    vector<int>vis(V,0);
    stack<int>st;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs(i,vis,st,adj);
        }
    }
    vector<int>ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
vector<int> dist(int V, vector<vector<int>> &edge, int src){
    // we will build the adj list from edge data
    // syntax pe batchet
    // vector<int>adj[n] -> ye banayega ek vector of N array where each array stores int data type
    // vector<pair<int,int>> adj[n] -> ye banayega ek vector of N array where eacha array will store pairs of integers
    vector<pair<int,int>> adj[V]; 
    for(auto & e: edge){
        int u = e[0];
        int v = e[1];
        int w = e[2];
        adj[u].push_back({v,w});
    }
    vector<int> topo = toposort(V, adj);
   vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    for(int node : topo){
        if(dist[node] == INT_MAX) continue;
        for(auto it: adj[node]){
            int v = it.first;
            int w = it.second;
            if(dist[node] + w < dist[v]){
                dist[v] = w + dist[node];
            }
        }
    }
    // unreachable nodes ko -1 mark kardiya
    for(int i=0;i<V;i++){
        if(dist[i] == INT_MAX){
            dist[i] = -1;
        }
    }
    return dist;
    
}
int main(){
    
    return 0;
}