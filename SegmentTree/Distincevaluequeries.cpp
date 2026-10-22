#include <bits/stdc++.h>
using namespace std;
struct SegTree {
    int n;
    vector<int> st;
    SegTree(int n) : n(n), st(4*n, 0) {}
    void upd(int i, int v, int x, int l, int r) {
        if(l == r) {
            st[x] = v;
            return;
        }
        int m = (l+r)/2;
        if(i <= m) upd(i, v, 2*x+1, l, m);
        else upd(i, v, 2*x+2, m+1, r);
        st[x] = st[2*x+1] + st[2*x+2];
    }
    void upd(int i, int v) {
        upd(i, v, 0, 0, n-1);
    }
    int query(int ql, int qr, int x, int l, int r) {
        if(qr < l || r < ql) return 0;
        if(ql <= l && r <= qr) return st[x];
        int m = (l+r)/2;
        return query(ql, qr, 2*x+1, l, m) +
               query(ql, qr, 2*x+2, m+1, r);
    }
    int query(int l, int r) {
        return query(l, r, 0, 0, n-1);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    vector<vector<pair<int,int>>> qr(n);
    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        qr[r].push_back({l, i});
    }
    SegTree st(n);
    vector<int> ans(q);
    map<int,int> last;
    for(int i = 0; i < n; i++) {
        if(last.count(a[i])) {
            st.upd(last[a[i]], 0);
        }
        st.upd(i, 1);
        last[a[i]] = i;
        for(auto it : qr[i]) {
            int l = it.first;
            int id = it.second;
            ans[id] = st.query(l, i);
        }
    }
    for(int x : ans) {
        cout << x << endl;
    }
    return 0;
}
