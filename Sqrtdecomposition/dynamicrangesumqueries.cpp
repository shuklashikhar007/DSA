
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

class SegTree{
    vector<ll>seg;
    int n;
    public:
    SegTree(int n){
        this->n = n;
        seg.assign(4LL*n,0);
    }
    void build(int node, int l , int r,vector<ll>&a){
        if(l == r){
            // matlal leaf node par agye
            // corresponding value daldo aur return kardo yaha se
            seg[node] = a[l];
            return;
        }
        // agar leaf node par nahi hai to 
        // move towards a left and a right subtree
        int mid = l + (r-l)/2;
        build(2*node+1,l,mid,a);
        build(2*node+2,mid+1,r,a);
        // jab wapis return karege to value update karte hue jayenge
        seg[node] = seg[2*node+1] + seg[2*node+2];
    }
    void update(int id, ll val, int node, int l , int r){
        // abb left right jayege jab tak apne req node par nahi pahuch jate hai
        if(l == r){
            seg[node] = val;
            return;
        }
        int mid = l + (r-l)/2;
        if(id <= mid){
            update(id, val, 2*node+1, l , mid);
        }
        else{
            update(id,val,2*node+2,mid+1,r);
        }
        seg[node] = seg[2*node+1] + seg[2*node+2];
    }
    ll query(int st, int end,int node, int l, int r){
        // teen case
        // pehla case -> no overlap
        if(end < l || st > r){
            return 0LL;
        }
        // pura complete overlap
        if(st <= l && r <= end){
            return seg[node];
        }
        int mid = l + (r-l)/2;
        ll left = query(st,end,2*node+1,l,mid);
        ll right = query(st,end,2*node+2,mid+1,r);
        return left + right;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vector<ll>a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    SegTree seg(n);
    seg.build(0,0,n-1,a);

    vector<ll>ans;
    while (m--)
    {
        int t,u;
        ll v;
        cin >> t >> u >> v;
        if(t==1){
            // agar value update query hai to 
            seg.update(u-1,v,0,0,n-1);
        }   
        else{
            // agar retrival query hai to 
            ans.push_back(seg.query(u-1,(int)v-1,0,0,n-1));
        }
    }
    for(ll x : ans){
        cout << x << '\n';
    }
    return 0;
}
