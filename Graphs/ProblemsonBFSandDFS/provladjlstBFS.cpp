#include<bits/stdc++.h>
using namespace std;
void bfs(int start, vector<vector<int>> &adj, vector<int>vis){
    queue<int>q;
    q.push(start);
    vis[start] = 1;

    while(!q.empty()){
        int node = q.front();
        for(int neigh : adj[node]){
            if(!vis[neigh]){
                vis[neigh] = 1;
                q.push(neigh);
            }
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
    int pro = 0;

    for(int i = 0;i<n;i++){
        if(!vis[i]){
            pro++;
            bfs(i,adj,vis);
        }
    }
    cout << pro << endl;
    return 0;
}