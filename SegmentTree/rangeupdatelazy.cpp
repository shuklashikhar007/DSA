#include<bits/stdc++.h>
using namespace std;
using ll = long long;

class Segtree{
    vector<ll>seg,lazy;
    int n;
    public:
    Segtree(int n){
        seg.assign(4*n,0);
        lazy.assign(4*n,0);
        this->n = n;
    }

    void build(int node, vector<ll>&a, int l , int r){
        if(l == r){
            seg[node] = a[l];
            return;
        }
        int mid = l + (r-l)/2;
        build(2*node+1,a,l,mid);
        build(2*node+2,a,mid+1,r);
        seg[node] = seg[2*node+1] + seg[2*node+2];
    }

    void push(int node, int l, int r){
        // ye function lazy update ke liye use hoga
        if(lazy[node] == 0) return; // matlab is node par kuch pending nahi hai update

        seg[node] += (r-l+1)*lazy[node];

        if(l != r){ // agar is node ke niche jo nodes hai wo leaf node nahi hai
            // to hame pendency pass on karni padegi;
            lazy[2*node+1] += lazy[node];
            lazy[2*node+2] += lazy[node];
        }

        lazy[node] = 0; // pendency remove kar denge is wali particular node se hamlog 
    }

    void update(int st, int end ,ll val, int node, int l , int r){
        push(node,l,r);

        if(st > r || end < l){
            return;
        }

        // complete overlap 
        if(st <= l && r <= end){
            lazy[node] += val;
            push(node,l,r); // ispar koi pending update to nahi hai check 
            // else do lazy update here
            // to hamne kind of ek range update ko point update mai convert kar diya
            return;
        }

        int mid = l + (r-l)/2;
        update(st,end,val,2*node+1,l,mid);
        update(st,end,val,2*node+2,mid+1,r);

        seg[node] = seg[2*node+1] + seg[2*node+2];
    }

    ll query(int st, int end, int node, int l, int r){
        // no overlap wala case
        if(st > r || end < l){
            return 0;
        }

        push(node,l,r); 
        // check ki current node par koi pending update to nahi hai

        // complete overlap wala case
        if(st <= l && r <= end){
            return seg[node];
        }

        int mid = l + (r-l)/2;
        ll x = query(st,end,2*node+1,l,mid);
        ll y = query(st,end,2*node+2,mid+1,r);

        return x+y;
    }

    void update(int l, int r, ll val){
        update(l,r,val,0,0,n-1);
    }

    ll query(int l, int r){
        return query(l,r,0,0,n-1);
    }
};

int main(){
    int n,m;
    cin >> n >> m;

    vector<ll>a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    Segtree st(n);
    st.build(0,a,0,n-1);

    vector<ll>ans;

    while(m--)
    {
        int t,l,r;
        cin >> t;

        if(t==1){
            ll u;
            cin >> l >> r >> u;
            l--,r--;
            st.update(l,r,u);
        }
        else{
            cin >> l;
            l--; // 1-based indexing ko 0-based mai convert karenge
            ans.push_back(st.query(l,l));
        }
    }

    for(ll x : ans){
        cout << x << endl;
    }

    return 0;
}