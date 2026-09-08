#include<bits/stdc++.h>
using namespace std;
long long countPairsGreaterThanX(vector<int>& a, int x) {
    sort(a.begin(), a.end());
    int n = a.size();
    long long cnt = 0;
    int l = 0, r = n - 1;
    while (l < r) {
        if (a[l] + a[r] > x) {
            cnt += (r - l);  // all pairs (l...r-1, r)
            r--; // r ke sare pairs cnt hogaye abb piche jao 
        } else {
            l++; // sum x se kaam hai to piche jane ki jarrurat hai hame
        }
    }
    return cnt;
}
int main(){

    return 0;
}