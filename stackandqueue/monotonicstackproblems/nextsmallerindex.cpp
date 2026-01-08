// yaha pe value and index dono store kare hai hamne 
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll n;
    cin >> n;
    vector<ll>a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    stack<pair<int,int>>st;
    // value aur index dono store karenge yaha pe
    vector<int>NSE(n);
    for(int ind = 0;ind < n;ind++){
        while (!st.empty() && st.top().first >= a[ind])
        {
            st.pop();
        }
        NSE[ind] = st.empty() ? 0 : st.top().second+1;
        st.push({a[ind] , ind});
    }
    for(int i=0;i<NSE.size();i++){
        cout << NSE[i] << " " ;
    }
    return 0;
}