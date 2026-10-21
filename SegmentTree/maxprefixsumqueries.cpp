// How to find the max prefix sum in range [a,b] in O(logn) complexity
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
class Segtree{
    vector<pair<ll,ll>>seg;
    int n;
    pair<ll,ll>merge(pair<ll,ll>a, pair<ll,ll>b){
        return{
            a.first + b.first,
            max(a.second, a.first + b.second)
        };
    }
public:
    Segtree(vector<ll>&a){
        n = a.size();
        seg.resize(4*n);
        build(0,0,n-1,a);
    }
    void build(int node, int l, int r, vector<ll>&a){
        if(l == r){
            // 0 for neg numbers since not taking anything bhi ek valid prefix sum counted hai yaha par
            seg[node] = {a[l],max(0LL,a[l])};
            return;
        }
        int mid = l + (r-l)/2;
        build(2*node+1,l,mid,a);
        build(2*node+2,mid+1,r,a);
        seg[node] = merge(seg[2*node+1],seg[2*node+2]);
    }
    void update(int node, int l , int r, int idx, ll val){
        if(l==r){
            seg[node] = {val,max(0LL,val)};
            return;
        }
        int mid = l + (r-l)/2;
        if(idx <= mid){
            update(2*node+1,l,mid,idx,val);
        }
        else{
            update(2*node+2,mid+1,r,idx,val);
        }
        seg[node] = merge(seg[2*node+1], seg[2*node+2]);
    }
    pair<ll,ll>query(int node, int l, int r, int ql , int qr){
        if(ql < r || qr > l){
            return {0,0};
        }
        // complete overlap wala case hai ye
        if(l <= ql && qr <= r){
            return seg[node];
        }
        // partial overlap wala case
        int mid = l + (r-l)/2;
        auto a = query(2*node+1,l,mid,ql,qr);
        auto b = query(2*node+2,mid+1,r,ql,qr);
        return merge(a,b);
    }
    void update(int idx, ll val){
        update(0,0,n-1,idx,val);
    }
    ll query(int l, int r){
        return query(0,0,n-1,l,r).second;
    }
};
int main(){
    int n,q;
    cin >> n >> q;
    vector<ll>a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    Segtree st(a);
    while (q--)
    {
        int type,a,b;
        cin >>type>> a >> b;
        if(type == 1){
            st.update(a-1,b);
        }   
        else{
            cout << st.query(a-1,b-1) << endl;
        }
    }
    return 0;
}