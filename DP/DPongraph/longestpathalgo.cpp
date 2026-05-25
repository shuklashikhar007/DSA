#include<bits/stdc++.h>
using namespace std;
int dfs(int node, vector<vector<int>>& adj, vector<int>& dp){
    if(dp[node] != -1) return dp[node];
    int ans = 0; // longest path in terms of edges
    for(auto nxt : adj[node]){
        // if next node has no outgoing edges,
        // dfs(next) returns 0 automatically
        ans = max(ans, 1 + dfs(nxt, adj, dp));
    }
    return dp[node] = ans;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> dp(n + 1, -1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, dfs(i, adj, dp));
    }
    cout << ans << endl;
    return 0;
} // LC - jump game 5