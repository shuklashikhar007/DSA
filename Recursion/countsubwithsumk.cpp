#include<bits/stdc++.h>
using namespace std;

int generate(int ind, vector<int>& a, int rsum, int sum, int n, vector<int>& ds){
    if(ind == n){
        if(rsum == sum){
           return 1;
        }
        else return 0;
    }
    // lelo
    ds.push_back(a[ind]);
    int lelo = generate(ind + 1, a, rsum + a[ind], sum, n, ds);
    // matlo
    ds.pop_back();
    int matlo = generate(ind + 1, a, rsum, sum, n, ds);

    return lelo + matlo;
}
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n), ds;
    for(int i = 0; i < n; i++) cin >> a[i];
    int ans = generate(0, a, 0, k, n, ds);
    cout << "no of subseq jinka sum k hai are : " << ans << endl;
    return 0;
}
