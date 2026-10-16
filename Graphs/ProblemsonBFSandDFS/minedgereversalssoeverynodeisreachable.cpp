#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs1(int node, int par, vector<vector<pair<int,int>>>& adj,
              vector<int>& ans) {
        for (auto [v, cost] : adj[node]) {
            if (v == par) continue;
            ans[0] += cost;
            dfs1(v, node, adj, ans);
        }
    }
    void dfs2(int node, int par, vector<vector<pair<int,int>>>& adj,
              vector<int>& ans) {
        for (auto [v, cost] : adj[node]) {
            if (v == par) continue;
            if(cost == 1){
                // pehle node->v edge nahi tha v->node edge tha
                ans[v] = ans[node] - 1;
            }
            else{
                // iska matlab pehle node->v edge tha 
                // to parent se child ko ek extra reversal chaiye hoga
                ans[v] = ans[node] + 1;
            }
            dfs2(v, node, adj, ans);
        }
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back({v, 0});
            adj[v].push_back({u, 1});
        }
        vector<int> ans(n, 0);
        dfs1(0, -1, adj, ans);
        dfs2(0, -1, adj, ans);
        return ans;
    }
};
int main(){
    return 0;
}