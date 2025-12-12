#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin  >> n >> m;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({u,w});
        adj[v].push_back({v,w});
    }
    return 0;
}