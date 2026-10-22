#include<bits/stdc++.h>
using namespace std;
using ll = long long;

class EulerTour {
public:
    vector<vector<int>> adj;
    vector<int> tin, tout, euler;
    int timer, n;

    EulerTour(int n) {
        this->n = n;
        adj.resize(n + 1);
        tin.resize(n + 1);
        tout.resize(n + 1);
        timer = 0;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int u, int p) {
        tin[u] = timer;
        euler.push_back(u);
        timer++;

        for(int v : adj[u]) {
            if(v == p) continue;
            dfs(v, u);
        }

        tout[u] = timer - 1;
    }

    void build(int root = 1) {
        timer = 0;
        euler.clear();
        dfs(root, 0);
    }
};

class Segtree {
public:
    vector<ll> seg;
    int n;

    Segtree(int n) {
        this->n = n;
        seg.resize(4 * n, 0);
    }

    void build(int idx, int l, int r, vector<ll>& a) {
        if(l == r) {
            seg[idx] = a[l];
            return;
        }

        int mid = (l + r) / 2;

        build(2 * idx + 1, l, mid, a);
        build(2 * idx + 2, mid + 1, r, a);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    void update(int idx, int l, int r, int pos, ll val) {
        if(l == r) {
            seg[idx] = val;
            return;
        }

        int mid = (l + r) / 2;

        if(pos <= mid) update(2 * idx + 1, l, mid, pos, val);
        else update(2 * idx + 2, mid + 1, r, pos, val);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    ll query(int idx, int l, int r, int ql, int qr) {
        if(r < ql || l > qr) return 0;

        if(ql <= l && r <= qr) return seg[idx];

        int mid = (l + r) / 2;

        return query(2 * idx + 1, l, mid, ql, qr)
             + query(2 * idx + 2, mid + 1, r, ql, qr);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<ll> val(n + 1);
    for(int i = 1; i <= n; i++) cin >> val[i];

    EulerTour et(n);

    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        et.addEdge(u, v);
    }

    et.build(1);

    vector<ll> flat(n);

    for(int i = 1; i <= n; i++) {
        flat[et.tin[i]] = val[i];
    }

    Segtree st(n);
    st.build(0, 0, n - 1, flat);

    while(q--) {
        int type, s;
        cin >> type >> s;

        if(type == 1) {
            ll x;
            cin >> x;
            st.update(0, 0, n - 1, et.tin[s], x);
        }
        else {
            cout << st.query(0, 0, n - 1,
                             et.tin[s], et.tout[s]) << "\n";
        }
    }

    return 0;
}