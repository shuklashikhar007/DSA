#include <bits/stdc++.h>
using namespace std;

/*
 can(m):
 check if we can place at least k teleports
 such that each teleport is at distance >= m
 from every friend
*/
bool canPlace(long long m, vector<long long>& a, int k, long long x) {
    long long cnt = 0;
    int n = a.size();

    // virtual boundaries
    a[0] = -m;
    a[n - 1] = x + m;

    for (int i = 1; i < n; i++) {
        long long L = a[i - 1] + m;
        long long R = a[i] - m;
        if (L <= R)
            cnt += (R - L + 1);
        if (cnt >= k) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        long long x;
        cin >> n >> k >> x;

        vector<long long> a(n);
        for (auto &v : a) cin >> v;

        // add sentinels
        a.push_back(-1e18);
        a.push_back(1e18);
        sort(a.begin(), a.end());

        // binary search on answer
        long long low = 0, high = x + 1;
        while (low + 1 < high) {
            long long mid = (low + high) / 2;
            if (canPlace(mid, a, k, x))
                low = mid;
            else
                high = mid;
        }

        // construct answer using best m = low
        long long m = low;
        a[0] = -m;
        a.back() = x + m;

        long long cur = 0;
        for (int i = 1; i < (int)a.size() && k > 0; i++) {
            long long L = max(cur, a[i - 1] + m);
            long long R = min(a[i] - m, x);
            for (long long pos = L; pos <= R && k > 0; pos++) {
                cout << pos << " ";
                k--;
                cur = pos + 1;
            }
        }
        cout << '\n';
    }
    return 0;
}
