#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    using ll = long long;
    vector<int> rk(string t, string p) {
        int n = t.size(), m = p.size();
        if(m > n) return {};
        ll B = 31;
        ll M = 1e9 + 7;
        ll ph = 0, th = 0, pw = 1;
        for(int i = 0; i < m - 1; i++)
            pw = (pw * B) % M;
        for(int i = 0; i < m; i++) {
            ph = (ph * B + p[i]) % M;
            th = (th * B + t[i]) % M;
        }
        vector<int> ans;
        for(int i = 0; i <= n - m; i++) {
            if(ph == th) {
                bool ok = true;
                for(int j = 0; j < m; j++) {
                    if(t[i + j] != p[j]) {
                        ok = false;
                        break;
                    }
                }
                if(ok) ans.push_back(i);
            }
            if(i < n - m) {
                th = (th - 1LL * t[i] * pw % M + M) % M;
                th = (th * B + t[i + m]) % M;
            }
        }
        return ans;
    }
    int repeatedStringMatch(string a, string b) {
        string s = a;
        int cnt = 1;
        while(s.size() < b.size()) {
            s += a;
            cnt++;
        }
        if(!rk(s, b).empty())
            return cnt;
        s += a;
        if(!rk(s, b).empty())
            return cnt + 1;
        return -1;
    }
};
int main(){

    return 0;
}