#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    class DSU {
    public:
        vector<int> par, sz;
        int comp;
        DSU(int n) {
            par.resize(n);
            iota(par.begin(), par.end(), 0);
            sz.assign(n, 1);
            comp = n;
        }
        int findpar(int node) {
            if (par[node] == node) return node;
            return par[node] = findpar(par[node]);
        }
        void unite(int u, int v) {
            int pu = findpar(u);
            int pv = findpar(v);
            if (pu == pv) return;
            if (sz[pu] < sz[pv]) swap(pu, pv);
            par[pv] = pu;
            sz[pu] += sz[pv];
            comp--;
        }
        int getcomp() {
            return comp;
        }
    };
    bool check(int cost, vector<vector<pair<int, int>>> &adj, int k, int n) {
        DSU ds(n);
        for (int u = 0; u < n; u++) {
            for (auto &nei : adj[u]) {
                int v = nei.first;
                int wt = nei.second;
                if (wt <= cost) {
                    ds.unite(u, v);
                }
            }
        }
        return ds.getcomp() <= k;
    }
    int minCost(int n, vector<vector<int>>& edges, int k) {
        int mini = INT_MAX, maxi = INT_MIN;
        vector<vector<pair<int, int>>> adj(n);
        for (auto &it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            mini = min(mini, wt);
            maxi = max(maxi, wt);
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        int l = 0, h = 1e8, ans = -1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (check(mid, adj, k, n)) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
int main(){

    return 0;
}