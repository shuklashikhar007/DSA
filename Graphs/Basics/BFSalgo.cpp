#include <bits/stdc++.h>
using namespace std;
// Returns BFS traversal order covering all components (1-based nodes)
vector<int> bfstrav(const vector<vector<int>> &adj) {
    int n = (int)adj.size() - 1; // adj is sized n+1 (1-based)
    vector<int> order;
    vector<char> vis(n + 1, false);
    queue<int> q;
    for (int start = 1; start <= n; ++start) {
        if (vis[start]) continue;
        // start a BFS from 'start'
        vis[start] = true;
        q.push(start);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            order.push_back(u);
            for (int v : adj[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    return order;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1); // 1-based
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> bfs = bfstrav(adj);
    // Example: print traversal
    for (int x : bfs) cout << x << ' ';
    cout << '\n';
    return 0;
}
