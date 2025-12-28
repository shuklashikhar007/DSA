#include<bits/stdc++.h>
using namespace std;
void generate(int ind, vector<int>& a, int rsum, int sum, int n, vector<int>& ds){
    if(ind == n){
        if(rsum == sum){
            for(int x : ds) cout << x << " ";
            cout << endl;
        }
        return;
    }
    // take
    ds.push_back(a[ind]);
    generate(ind + 1, a, rsum + a[ind], sum, n, ds);
    // not take
    ds.pop_back();
    generate(ind + 1, a, rsum, sum, n, ds);
}
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n), ds;
    for(int i = 0; i < n; i++) cin >> a[i];
    generate(0, a, 0, k, n, ds);
    return 0;
}
