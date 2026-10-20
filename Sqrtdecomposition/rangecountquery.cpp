// for range [L,R] how many elements in this range have value b/w a interval [a,b]
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>x(n);
    for(int i=0;i<n;i++) cin >> x[i];
    int sq = sqrt(n);
    int i = 0;
    vector<int>y = x;
    // block wise sort kar lenge taki baad mai binary search laga sake ham
    while (i<n)
    {
        int j = min(i+sq,n);
        sort(y.begin()+i,y.begin()+j);
        i += sq;
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l,  r, a,b;
        cin >> l >> r >> a >> b;
        int block_l = l/sq;
        int block_r = r/sq;
        int ans= 0;
        if(block_l == block_r){
            // agar both l and r lie in a single block
            for(int i=l ; i <= r; i++){
                ans += (a <= x[i]) && (x[i] <= b);
            }
        }
        else{
            // pehle left wala partial block
            int block_l_end = (block_l+1)*sq -1;
            for(int i=l;i<=block_l_end;i++){
                ans += (a <= x[i] && x[i] <= b);
            }
            // middle part wala block
            // iss part mai sidha binary search lagayenege
            // for the edge case jab sirf do blocks mai iterate karna hoga ye wala loop chalega hi nahi
            /// to usse ye edge case bhi cover ho jayega yaha par
            for(int i=block_l+1 ; i <= block_r-1; i++){
                int st = sq*i, ed = sq*(i+1);
                ed = min(ed,n);
                auto it1 = lower_bound(y.begin()+st,y.begin()+ed,a);
                auto it2 = upper_bound(y.begin()+st,y.begin()+ed,b);
                ans += (it2-it1);
            }
            // right final partial part
            int blockrst= block_r*sq;
            for(int i=blockrst ;i <= r; i++){
                ans += (a <= x[i] && x[i] <=b);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
