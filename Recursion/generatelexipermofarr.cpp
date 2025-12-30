// this can be done in two ways first using in build or writing manually
#include <bits/stdc++.h>
using namespace std;
bool nextPermutation(vector<int>& a) {
    int n = a.size();
    int ind = -1;
    // phele break point jahape piche se are pehle bar dec ho
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] < a[i + 1]) {
            ind = i;
            break;
        }
    }
    if (ind == -1) {
        reverse(a.begin(), a.end());
        return false;
    }
    // find nearest greatest element to pivot element
    for (int i = n - 1; i > ind; i--) {
        if (a[i] > a[ind]) {
            // swap them 
            swap(a[i], a[ind]);
            break;
        }
    }
    // reverse the now left array to make it sorted after the pivot index
    reverse(a.begin() + ind + 1, a.end());
    return true;
}


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());   
    do {
        for(int x : a) cout << x << " ";
        cout << '\n';
    } while (next_permutation(a.begin(), a.end()));
    return 0;
}
