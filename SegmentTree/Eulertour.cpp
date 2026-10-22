#include<bits/stdc++.h>
using namespace std;
class EulerTour{
    vector<vector<int>>adj;
    vector<int> tin, tout, euler;
    int timer, n;
    public:
    EulerTour(int n){
        this->n = n;
        adj.resize(n+1);
        tin.resize(n+1);
        tout.resize(n+1);
        timer = 0;
    }
    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void dfs(int u, int p){
        tin[u] = timer;
        euler.push_back(u);
        timer++;
        for(int v : adj[u]){
            if(v==p) continue;
            dfs(v,u);
        }
        tout[u] = timer-1;
    }
    void build(int root = 1){
        timer = 0;
        euler.clear();
        dfs(root,0);
    }
};
int main(){
    int n;
    cin >> n;
    EulerTour et(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        et.addEdge(u,v);
    }
    et.build(1);
    return 0;
}