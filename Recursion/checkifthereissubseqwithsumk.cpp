#include<bits/stdc++.h>
using namespace std;
bool generate(int ind, vector<int>& a, int rsum, int sum, int n, vector<int>& ds){
    if(ind == n){
        if(rsum == sum){
           return true;
        }
        else return false;
    }
    // lelo
    ds.push_back(a[ind]);
    bool liya = generate(ind + 1, a, rsum + a[ind], sum, n, ds);
    // matlo
    ds.pop_back();
    bool nahiliya = generate(ind + 1, a, rsum, sum, n, ds);
    return liya || nahiliya;
}
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n), ds;
    for(int i = 0; i < n; i++) cin >> a[i];
    bool flag = generate(0, a, 0, k, n, ds);
    if(flag){
        cout << "HAI " << endl;
    }
    else cout << "NAHI HAI" << endl;
    return 0;
}
