#include <bits/stdc++.h>
using namespace std;

void permute(int ind, string &s) {
    if (ind == s.size()) {
        cout << s << '\n';
        return;
    }

    unordered_set<char> used;

    for (int i = ind; i < s.size(); i++) {
        if (used.count(s[i])) continue;
        used.insert(s[i]);
        swap(s[ind], s[i]);
        permute(ind + 1, s);
        swap(s[ind], s[i]); 
    }
}

int main() {
    string s;
    cin >> s;
    permute(0, s);
    return 0;
}
