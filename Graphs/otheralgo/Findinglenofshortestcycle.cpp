#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int bfs(int src, int n, vector<vector<int>>& adj) {
        vector<int> dist(n, -1);
        vector<int> parent(n, -1);
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        int ans = INT_MAX;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    parent[v] = u;
                    q.push(v);
                }
                else if (parent[u] != v) {
                    ans = min(ans, dist[u] + dist[v] + 1);
                }
            }
        }
        return (ans == INT_MAX ? -1 : ans);
    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int cur = bfs(i, n, adj);
            if (cur != -1)
                ans = min(ans, cur);
        }
        return (ans == INT_MAX ? -1 : ans);
    }
};
int main(){
    
    return 0;
}