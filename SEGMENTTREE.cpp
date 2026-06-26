#include<bits/stdc++.h>
using namespace std;
using ll = long long; 
class segmenttree{
    int n;
    vector<ll>tree;
    ll merge(ll lft, ll rgt){
        return lft + rgt;
    }
    public:
    segmenttree(vector<int>&arr){
        n = arr.size();
        tree.resize(4*n);
        build(0,0,n-1,arr);
    }
    void build(int node, int st, int end, vector<int>&arr){
        if(st == end){
            tree[node] = arr[st]; // leaf node pe agye base case 
            return;
        }
        int mid  = (st + end)/2;
        build(2*node+1, st, mid, arr);
        build(2*node+2,mid+1,end,arr);
        // pehle build karege fir upar ayege -> bottom up approach
        tree[node] = merge(tree[2*node+1], tree[2*node+2]);
        // yaha error isliye nahi ayega since ye dono already generate ho chuke honge
    }
    void update(int node, int st, int end, int idx, int val){
        // index idx par value update karke val karni hai in log(n)
        if(st == end){
            // pahuch gye ind wali node par
            tree[node] = val;
            return;
        }
        int mid = (st+end)/2;
        if(idx <= mid){ // is case mai search in left half
            update(2*node+1, st, mid,idx,val);
        }
        else{
            // opposite case mai search in right half
            update(2*node+2, mid + 1, end, idx, val);
        }
        
        // abb jab wapis return karege after all calls;
        tree[node] = merge(tree[2*node+1], tree[2*node+2]);
        // values update karte jayege
    }
    ll query(int node, int st, int end, int l , int r){
        // no overlap wala case
        if(l > end || r < st){
            return 0;
        }
        // pura overlap wala case return node val
        else if(l >= st && r <= end){
            return tree[node];
        }
        // partial overlap wala case
        else{
            int mid = (st + end)/2;
            ll left = query(2*node+1,st,mid,l,r);
            ll right = query(2*node+2,mid+1,end,l,r);
            return merge(left,right); // return sum of both left and right wale case
        }
    }
    void update(int idx, int val){
        update(0,0,n-1,idx,val);
    }
    ll query(int l, int r){
        return query(0,0,n-1,l,r);
    }
};
int main(){
    // same code can be used to solve max min in range wali problem as well
    // list of all possible problems jo isse solve hoti hai
    /*
    Range Sum Query
Range Minimum Query (RMQ)
Range Maximum Query
Range GCD Query
Range LCM Query
Range XOR Query
Range AND Query
Range OR Query
Range Product Query
Point Update + Range Query
Range Update + Point Query
Range Update + Range Query (Lazy Propagation)
Count of Ones in a Range
Count of Zeros in a Range
Count of Even/Odd Numbers
Count of Positive/Negative Numbers
Frequency of an Element in a Range
Majority Element Query
Maximum Prefix Sum Query
Maximum Suffix Sum Query
Maximum Subarray Sum Query
Minimum Subarray Sum Query
Longest Consecutive Ones
Longest Consecutive Zeros
Balanced Parentheses Queries
K-th One Query
K-th Zero Query
K-th Smallest Element (with frequency tree)
Order Statistics
First Element Greater Than X
First Element ≥ X
Last Element ≤ X
Lower Bound on Prefix Sum
Hotel Room Allocation
Dynamic Inversion Count
Dynamic Frequency Queries
Distinct Elements in a Range (advanced variants)
Merge Sort Tree Queries
Maximum Pair Sum Query
Maximum Difference Query
Minimum Difference Query
Matrix Multiplication Queries
Polynomial Evaluation Queries
Affine Transformation Queries
Function Composition Queries
Range Assignment Updates
Range Addition Updates
Range Multiplication Updates
Range Flip (0 ↔ 1)
Range Toggle Queries
Segment Tree Beats (Range Chmin/Chmax/Add)
Persistent Segment Tree Queries
2D Segment Tree Queries
Dynamic Segment Tree Queries
Coordinate Compression + Segment Tree Problems
Offline Query Processing with Segment Tree
Sweep Line + Segment Tree Problems
Rectangle Union Area
Skyline Problem
Interval Overlap Queries
    */
    return 0;
}