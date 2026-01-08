// accha question to revise sliding window concept
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll n;
    cin >> n;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    int i=0, j=0;
    ll ans = 0;
    // ye solution optimal hai O(nlogn)
    map<int,int>mpp; // map to store freq of each element in current window from i to j
    while (j<n)
    {
        mpp[a[j]]++;
        while (mpp[a[j]] > 1)
        {
            // jab tak newly added element ki freq 1 se jyada hai means array mai duplicates hai
            // window ko left se keep shrinking till no duplicates in window
            mpp[a[i]]--;
            i++;
        }
         ans += (j-i+1); // i se j tak currentwindow ki possible subarrays
         j++;
         // increase window size and next iteration karo
    }
    cout << ans << endl;
    return 0;
}