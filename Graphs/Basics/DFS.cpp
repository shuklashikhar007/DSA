#include <bits/stdc++.h>
using namespace std;
void dfs(int u, const vector<vector<int>> &adj, vector<char> &vis, vector<int> &order) {
    vis[u] = true;
    order.push_back(u);

    for (int v : adj[u]) {
        if (!vis[v]) dfs(v, adj, vis, order);
    }
}
vector<int> dfstrav(const vector<vector<int>> &adj) {
    int n = (int)adj.size() - 1; 
    vector<char> vis(n + 1, false);
    vector<int> order;

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, adj, vis, order);
        }
    }
    return order;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dfsorder = dfstrav(adj);
    // print dfs traversal
    for (int x : dfsorder) cout << x << ' ';
    cout << '\n';
    return 0;
}
