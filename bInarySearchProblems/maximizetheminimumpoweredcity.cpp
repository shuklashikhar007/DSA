#include<bits/stdc++.h>
using namespace std;
// LC 2528 Teradata OA -> binary search on answer 
class Solution {
public:
    // binary search ka sabse accha question 
    using ll = long long;
    bool check(vector<ll>&power, int r, int k, ll target){
        int n = power.size();
        vector<ll>add(n,0);
        ll cradd = 0;
        ll used = 0;
        for(int i=0;i<n;i++){
            // expired help jo piche se a rahi thi usko hata denge pehle to
            if(i>r){
                cradd -= add[i-r-1];
            }
            if(power[i] + cradd < target){
                ll need = target - power[i] - cradd;
                if(used + need > k){
                    return false;
                }
                // greedily add the extra wale stations to the rightmost station in coverrage taki maximum logo ka fyada ho yaha pe
                int pos = min(n-1,i+r);
                add[pos] += need;
                cradd += need;
                used += need;
            }
        }
        return true;
    }
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<ll>prefix(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1] = prefix[i] + stations[i];
        }
        vector<ll>power(n);
        for(int i=0;i<n;i++){
            int left = max(0,i-r);
            int right = min(n-1,i+r);
            power[i] = prefix[right+1] - prefix[left];
        }
        ll l = 0, h = 1e15;
        ll ans = -1;
        while(l <= h){
            ll mid = l + (h-l)/2;
            if(check(power,r,k,mid)){
                ans = mid;
                l = mid + 1;
            }
            else{
                h = mid - 1;
            }
        }
        return ans;
    }
};
int main(){

    return 0;
}