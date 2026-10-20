#include<bits/stdc++.h>
using namespace std;
class SegTree{
    typedef long long ll;
    vector<ll>seg,lazy;
    int n;
    void app(int node, int len, ll val){
        seg[node] += val*val;
        lazy[node] += val;
    }
    void push(int node, int start, int end){
        // agar cur node par kuch pending nahi hai ya ye ek leaf node hai to return 
        if(lazy[node] == 0 || start == end) return;
        // agar esa nahi hai to pass the pending to both children 
        int mid = (start+end)/2;
        app(2*node+1,mid-start+1,lazy[node]);
        app(2*node+2,end-mid,lazy[node]);
        // remove pending tag of this particular node
        lazy[node] = 0;
    }
    void upd(int node, int start, int end, int l, int r ,ll val){
        // koi overlap nahi hai
        if(l > end || r < start) return;
        // complete overlap hai 
        if(l <= start && end <= r){
            app(node, end-start+1,val);
            return;
        }
        // partial overlap matlab niche wali nodes use hongi baad mai 
        // to cur par pendency nahi rakh sakte hai
        push(node,start,end);
        int mid = (start+end)/2;
        upd(2*node+1,start,mid,l,r,val);
        upd(2*node+2,start,mid,l,r,val);
        // update karne ke bad segment tree mai update 
        seg[node] = seg[2*node+1] + seg[2*node+2];
    }
    ll query(int node, int start, int end, int l, int r){
        if(l> end || start < r){
            return 0;
        }
        if(l <= start && end <= r) return seg[node];
        push(node, start, end);
        int mid = (start + end)/2;
        return query(2*node+1,start,mid,l,r) + query(2*node+2,mid+1,end,l,r);
    }
    public:
    SegTree(int n){
        this->n = n;
        seg.assign(4*n,0);
        lazy.assign(4*n,0);
    }
    SegTree(vector<int>&a){
        n = a.size();
        seg.assign(4*n,0);
        lazy.assign(4*n,0);
        build(0,0,n-1,a);
    }
    void build(int node, int start, int end, vector<int>&a){
        if(start == end){
            seg[node] = a[start];
            return;
        }
        int mid = (start+end)/2;
        build(2*node+1,start,mid,a);
        build(2*node+2,mid+1,end,a);
        seg[node] = seg[2*node+1] + seg[2*node+2];
    }
    void update(int l, int r, ll val){
        upd(0,0,n-1,l,r,val);
    }
    ll query(int l, int r){
        return query(0,0,n-1,l,r);
    }
};
int main(){
    
    return 0;
}