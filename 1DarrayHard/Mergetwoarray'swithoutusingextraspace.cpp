#include <bits/stdc++.h>
using namespace std;
#define int long long
void mergeArrays(vector<int>& a, vector<int>& b, int n, int m) {
    int l = n - 1;
    int r = 0;
    // Swap larger elements of a with smaller elements of b
    while (l >= 0 && r < m) {
        if (a[l] > b[r]) {
            swap(a[l], b[r]);
            l--;
            r++;
        }
        else {
            break;
        }
    }

    // Re-sort both arrays
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}

signed main() {

    int t;
    cin >> t;

    while (t--) {

        int n, m;
        cin >> n >> m;

        vector<int> a(n), b(m);

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        mergeArrays(a, b, n, m);

        for (auto x : a) cout << x << " ";
        for (auto x : b) cout << x << " ";
        cout << "\n";
    }

    return 0;
}