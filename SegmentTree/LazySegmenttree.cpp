#include<bits/stdc++.h>
using namespace std;
class Solution {
    typedef long long ll;
    vector<ll> seg, sq, lazy;

    void app(int node, int len, ll val) {
        sq[node] += 2*val*seg[node] + val*val*len;
        seg[node] += val*len;
        lazy[node] += val;
    }

    void upd(int node, int l, int r, int L, int R) {
        if(L <= l && r <= R) {
            app(node, r-l+1, 1);
            return;
        }

        int mid = (l+r)/2;

        if(lazy[node]) {
            app(2*node+1, mid-l+1, lazy[node]);
            app(2*node+2, r-mid, lazy[node]);
            lazy[node] = 0;
        }

        if(L <= mid) upd(2*node+1, l, mid, L, R);
        if(R > mid) upd(2*node+2, mid+1, r, L, R);

        seg[node] = seg[2*node+1] + seg[2*node+2];
        sq[node] = sq[2*node+1] + sq[2*node+2];
    }

public:
    int sumCounts(vector<int>& nums) {
        const ll MOD = 1e9+7;
        int n = nums.size();

        seg.assign(4*n, 0);
        sq.assign(4*n, 0);
        lazy.assign(4*n, 0);

        vector<int> last(100001, -1);
        ll ans = 0;

        for(int i = 0; i < n; i++) {
            upd(0, 0, n-1, last[nums[i]]+1, i);
            last[nums[i]] = i;
            ans = (ans + sq[0]) % MOD;
        }

        return ans;
    }
};
int main(){

}
