// this is a algorithmn used to match a pattern with a string 
// in O(n) time complexity effectively
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> rk(string t, string p){
    int n = t.size(), m = p.size();
    ll B = 31;
    ll M = 1e9 + 7;
    ll ph = 0, th = 0, pw = 1;
    for(int i=0;i<m-1;i++){
        pw = (pw*B) % M;
    }
    for(int i=0;i<m;i++){
        ph = (ph*B + p[i]) % M;
        th = (th*B + t[i]) % M;
    }
    vector<int>ans;
    for(int i=0; i<= n-m; i++){
        if(ph == th){ // agar rolling hash same hai to shayad match ho sakta hai 
            bool ok = 1;
            for(int j=0; j<m;j++){
                if(t[i+j] != p[j]){
                    ok = 0; // beech mai kahi bhi match break hua false kardo
                    break;
                }
            }
            if(ok) ans.push_back(i);
        }
        if(i < n-m){
            th = (th-t[i]*pw%M + M) % M; // purana char hata do 
            th = (th * B + t[i+m]) % M; // naya laga do
        }
    }
    return ans;
}
int main(){
    string t,p;
    cin >> t >> p;
    vector<int>v = rk(t,p);
    for(int x : v){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}