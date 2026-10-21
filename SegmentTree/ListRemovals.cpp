//
/*
proof of the idea in this question here =>
At every recursive call, k is between 1 and the number of available positions in the current range.
- If we go left, k remains valid because \(k \le cnt\).
- If we go right, we subtract cnt. Since \(k > cnt\), the new k is positive and does not exceed the available count in the right subtree.
- At a leaf, the range contains exactly one position. Because k is valid, k = 1, meaning that leaf must have seg[node] = 1.
This works because every query guarantees \(1 \le k \le\) the number of remaining elements.

*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
class Segtree{
    vector<int>seg;
    int n;
    public:
    Segtree(int n){
        this->n = n;
        seg.assign(4*n,0);
    }
    void build(int node, int l, int r){
        if(l == r){
            // since starting mai har position avail hogi
            seg[node] = 1;
            return;
        }
        int mid = l + (r-l)/2;
        build(2*node+1,l,mid);
        build(2*node+2,mid+1,r);
        seg[node] = seg[2*node+1] + seg[2*node+2];
    }
    // kth available pos dhundne ka function
    int kth(int node, int l , int r, int k){
        if(l == r){
            return l; // agar leaf node par agaye hai ham to
        }
        int mid = (l+r)/2;
        int cnt = seg[2*node+1];
        if(k <= cnt){
            return kth(2*node+1,l,mid,k);
        }
        // else right jayenge
        return kth(2*node+2,mid+1,r,k-cnt);
    }
    void update(int node, int l, int r, int pos){
        if(l == r){
            seg[node] = 0;
            return;
        }
        int mid = (l+r)/2;
        if(pos <= mid){
            update(2*node+1,l,mid,pos);
        }
        else update(2*node+2,mid+1,r,pos);
        seg[node] = seg[2*node+1] + seg[2*node+2];
    }
};
int main(){
    int n;
    cin >> n;
    vector<ll>a(n);
    for(int i=0;i<n;i++) cin  >> a[i];
    Segtree st(n);
    st.build(0,0,n-1);
    for(int i=0;i<n;i++){
        int k;
        cin>> k;
        int pos = st.kth(0,0,n-1,k);
        cout << a[pos] << " ";
        st.update(0,0,n-1,pos);
    }
    cout << endl;
    return 0;
}