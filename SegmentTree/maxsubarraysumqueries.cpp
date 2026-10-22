// how to know max subarray sum in [a,b] in O(logn)
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
class segtree{
    vector<vector<ll>>seg;
    int n;
public:
    segtree(int n){
        this->n = n;
        seg.assign(4*n, vector<ll>(4, 0));
    }
    void build(int node, int l, int r, vector<int>&a, vector<int>&pref, vector<int>&suff){
        if(l == r){
            seg[node][0] = a[l];
            seg[node][1] = a[l];
            seg[node][2] = a[l];
            seg[node][3] = a[l];
            return;
        }
        // convention jo yaha par used hai
        // seg[node][0] -> total sum of range represented by this node
        // seg[node][1] -> max pref sum of range rep by this node
        // seg[node][2] -> max suff sum of range rep by this node
        // seg[node][3] -> max subarray sum of range rep by this node
        // abb kisi do node ko merge karte time ka logic 
        // seg[node][0] = seg[2*node+1][0] + seg[2*node+2][0] -> ye kam to sidha hi kar sakte hai ham yaha par
        // seg[node][1] = naye merged node ke max pref sum ke liye do posibility hai
        // pehli ki ho sakta hai jo pehle max pref sum tha wahi rahe ya fir - 2*node+1 ka tot sum + 2*node+2 ka max prefix naya max prefix bana le 
        // to yaha par seg[node][1] = max(seg[2*node+1][1], seg[2*node+1][0] + seg[2*node+2][1]); 
        // tesra update max suff sum ka
        // yaha bhi do case 1) purana suff sum hi max hai ya fir 2) left side ka suff + right ka tot sum 
        // seg[node][2] = max(seg[2*node+1][2], max(seg[2*node+1][2] + seg[2*node+2][0]);
        // final max sub sum ke liye -> max({lmax, rmax, left ka max suff + right ka max prefixsum})
        // seg[node][3] = max({seg[2*node+1][3], seg[2*node+2][3], seg[2*node+1][2] + seg[2*node+2][1]})
        int mid = l + (r-l)/2;
        build(2*node+1, l, mid, a, pref, suff);
        build(2*node+2, mid+1, r, a, pref, suff);
        seg[node][0] = seg[2*node+1][0] + seg[2*node+2][0];
        seg[node][1] = max(seg[2*node+1][1],seg[2*node+1][0] + seg[2*node+2][1]);
        seg[node][2] = max(seg[2*node+2][2],seg[2*node+2][0] + seg[2*node+1][2]);
        seg[node][3] = max({seg[2*node+1][3],seg[2*node+2][3], seg[2*node+1][2] + seg[2*node+2][1]});
    }
    void update(int idx, int val, int node, int l, int r){
        if(l == r){
            seg[node][0] = val;
            seg[node][1] = val;
            seg[node][2] = val;
            seg[node][3] = val;
            return;
        }
        int mid = l + (r-l)/2;
        if(idx <= mid){
            update(idx, val, 2*node+1, l, mid);
        }
        else{
            update(idx, val, 2*node+2, mid+1, r);
        }
        seg[node][0] = seg[2*node+1][0] + seg[2*node+2][0];
        seg[node][1] = max(seg[2*node+1][1],
                           seg[2*node+1][0] + seg[2*node+2][1]);
        seg[node][2] = max(seg[2*node+2][2],
                           seg[2*node+2][0] + seg[2*node+1][2]);
        seg[node][3] = max({seg[2*node+1][3],
                            seg[2*node+2][3],
                            seg[2*node+1][2] + seg[2*node+2][1]});
    }
    void update(int idx, int val){
        update(idx, val, 0, 0, n-1);
    }
    vector<ll> query(int node, int ql, int qr, int l, int r){
        if(qr < l || ql > r){
            return {0, LLONG_MIN, LLONG_MIN, LLONG_MIN};
        }
        if(ql <= l && r <= qr){
            return seg[node];
        }
        int mid = l + (r-l)/2;
        vector<ll>a = query(2*node+1, ql, qr, l, mid);
        vector<ll>b = query(2*node+2, ql, qr, mid+1, r);
        if(a[1] == LLONG_MIN) return b;
        if(b[1] == LLONG_MIN) return a;
        vector<ll>ret(4, 0);
        ret[0] = a[0] + b[0];
        ret[1] = max(a[1], a[0] + b[1]);
        ret[2] = max(b[2], b[0] + a[2]);
        ret[3] = max({a[3], b[3], a[2] + b[1]});
        return ret;
    }
    vector<ll> query(int l, int r){
        return query(0, l, r, 0, n-1);
    }
    ll ans(){
        return seg[0][3];
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int>a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    vector<int>pref(n), suff(n);
    pref[0] = a[0];
    for(int i=1; i<n;i++){
        pref[i] = pref[i-1] + a[i];
    }
    suff[n-1]= a[n-1];
    for(int i = n-2;i >= 0; i--){
        suff[i] = suff[i+1] + a[i];
    }
    segtree st(n);
    st.build(0, 0, n-1, a, pref, suff);
    while(m--){
        int k, x;
        cin >> k >> x;
        k--;
        st.update(k, x);
        cout << max(0LL, st.ans()) << endl;
    }
    return 0;
}
