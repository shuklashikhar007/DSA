
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

class Segtree{
    vector<int>seg;
    int n;

public:
    Segtree(int n){
        this->n = n;
        seg.assign(4*n, 0);
    }

    void update(int idx, int val, int node, int l, int r){
        if(l == r){
            seg[node] += val;
            return;
        }

        int mid = (l+r)/2;

        if(idx <= mid){
            update(idx, val, 2*node+1, l, mid);
        }
        else{
            update(idx, val, 2*node+2, mid+1, r);
        }

        seg[node] = seg[2*node+1] + seg[2*node+2];
    }

    void update(int idx, int val){
        update(idx, val, 0, 0, n-1);
    }

    int query(int ql, int qr, int node, int l, int r){
        if(qr < l || ql > r) return 0;

        if(ql <= l && r <= qr){
            return seg[node];
        }

        int mid = (l+r)/2;

        return query(ql, qr, 2*node+1, l, mid)
             + query(ql, qr, 2*node+2, mid+1, r);
    }

    int query(int l, int r){
        if(l > r) return 0;
        return query(l, r, 0, 0, n-1);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll>a(n), b;

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    int m = b.size();
    Segtree st(m);

    ll ans = 0;
    for(int i=0; i<n; i++){
        int idx = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        // Previously processed elements strictly greater than a[i]
        ans += st.query(idx+1, m-1);
        st.update(idx, 1);
    }
    cout << ans << endl;

    return 0;
}
