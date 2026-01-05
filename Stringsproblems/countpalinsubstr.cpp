#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(0); cin.tie(0);

int32_t main() {
    fastio;

    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;

    // Odd length palindromes
    for (int center = 0; center < n; center++) {
        int l = center, r = center;
        while (l >= 0 && r < n && s[l] == s[r]) {
            ans++;
            l--;
            r++;
        }
    }

    // Even length palindromes
    for (int center = 0; center < n - 1; center++) {
        int l = center, r = center + 1;
        while (l >= 0 && r < n && s[l] == s[r]) {
            ans++;
            l--;
            r++;
        }
    }

    cout << ans << endl;
}