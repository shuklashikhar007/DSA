#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Step 1: Sort the array
    sort(a.begin(), a.end());

    // Step 2: Apply the formula
    long long ans = 0;
    for (int j = 0; j < n; j++) {
        ans += a[j] * j;               // contribution as larger element
        ans -= a[j] * (n - j - 1);     // contribution as smaller element
    }

    cout << ans << "\n";
    return 0;
}
