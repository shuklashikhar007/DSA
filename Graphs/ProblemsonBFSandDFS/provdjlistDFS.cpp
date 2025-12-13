#include<bits/stdc++.h>
using namespace std;
void dfs(int node, vector<vector<int>> &adj, vector<int>&vis){
    vis[node]= 1;
    for(int neigh : adj[node]){
        if(!vis[neigh]){
            dfs(neigh,adj,vis);
        }
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>vis(n,0);
    int provinces = 0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            provinces++;
            dfs(i,adj,vis);
        }
    }
    cout << provinces << endl;
    return 0;
}