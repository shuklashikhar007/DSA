
#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;
    vector<int> st;
    vector<int> &euler, &dep;

    SegTree(int n, vector<int> &euler, vector<int> &dep)
        : n(n), euler(euler), dep(dep) {
        st.assign(4 * n, 0);
        build(0, 0, n - 1);
    }

    int merge(int a, int b) {
        // jiski depth minimum hai wo store hoga node mai
        if (dep[euler[a]] <= dep[euler[b]]) return a;
        return b;
    }

    void build(int i, int l, int r) {
        if (l == r) {
            st[i] = l;
            return;
        }

        int m = (l + r) / 2;
        build(2 * i + 1, l, m);
        build(2 * i + 2, m + 1, r);

        st[i] = merge(st[2 * i + 1], st[2 * i + 2]);
    }

    int query(int i, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return st[i];
        int m = (l + r) / 2;
        int a = query(2 * i + 1, l, m, ql, qr);
        int b = query(2 * i + 2, m + 1, r, ql, qr);
        // is cheez ka dhyan rakhna hai in subarray queries question as well
        return a+b;
        return merge(a, b);
    }

    int query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> euler, dep( n + 1), first(n + 1, -1);

    function<void(int, int, int)> dfs = [&](int u, int p, int d) {
        dep[u] = d;
        first[u] = euler.size();
        euler.push_back(u);

        for (int v : adj[u]) {
            if (v == p) continue;
            dfs(v, u, d + 1);
            euler.push_back(u);
        }
    };

    dfs(1, 0, 0);

    SegTree st(euler.size(), euler, dep);

    while (q--) {
        // iss approach se distance queries bhi solve kar sakte hai
        // dis(u,v) = dep[u] + dep[v] - 2*dep[lca(u,v)];
        int u, v;
        cin >> u >> v;
        int l = first[u], r = first[v];
        if (l > r) swap(l, r);
        int idx = st.query(l, r);
        cout << euler[idx] << endl;
    }
}
