#include<bits/stdc++.h>
using namespace std;
using ll = long long;
class Segtree{
    vector<ll>seg;
    int n;
public:
    Segtree(ll n){
        this->n = n;
        seg.assign(4*n,0);
    }
    void update(int idx, ll val, int node, int l, int r){
        if(l == r){
            seg[node] += val;
            return;
        }
        int mid = (l+r)/2;
        if(idx <= mid){
            update(idx,val,2*node+1,l,mid);
        }
        else{
            update(idx,val,2*node+2,mid+1,r);
        }
        seg[node] = seg[2*node+1] + seg[2*node+2];
    }
    void update(int idx, int val){
        if(idx < n){
            update(idx,val,0,0,n-1);
        }
    }
    ll query(int ql, int qr, int node, int l, int r){
        if(qr <  l || ql > r){
            return 0;
        }
        if(ql <= l && r <= qr){
            return seg[node];
        }
        int mid = (l+r)/2;
        return query(ql,qr,2*node+1,l,mid) + query(ql,qr,2*node+2,mid+1,r);
    }
    ll query(int l, int r){
        if(l>r) return 0;
        return query(l,r,0,0,n-1);
    }
};
void dfs(int u, int p, vector<int>&tin, vector<int>&tout, int &timer, vector<vector<int>>&adj){
    tin[u] = timer++;
    for(int v : adj[u]){
        if(v==p) continue;
        dfs(v,u,tin,tout,timer,adj);
    }
    tout[u] = timer-1;
}
int main(){
    int n,q;
    cin >>n >> q;
    vector<ll>a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    vector<vector<int>>adj(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin  >> u >> v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>tin(n),tout(n);
    int timer =0;
    dfs(0,-1,tin,tout,timer,adj);
    Segtree st(n+1);
    for(int u=0;u<n;u++){
        st.update(tin[u],a[u]);
        st.update(tout[u] + 1, -a[u]);
    }
    while(q--){
        int type,s;
        cin >> type >> s;
        s--;
        if(type == 1){
            ll x;
            cin >> x;
            ll delta = x-a[s];
            st.update(tin[s],delta);
            st.update(tout[s] + 1,-delta);
            a[s] = x;
        }
        else{
            cout << st.query(0,tin[s]) << endl;
        }
    }
    return 0;
}