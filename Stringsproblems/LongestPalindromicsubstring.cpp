// Problem: Longest Palindromic Substring (no DP)
// Approach: Expand around center (O(n^2))

#include <iostream>
using namespace std;

string expand(string s, int l, int r) {
    while (l >= 0 && r < s.size() && s[l] == s[r]) {
        l--; r++;
    }
    return s.substr(l + 1, r - l - 1);
}

string longestPalindrome(string s) {
    string res = "";
    for (int i = 0; i < s.size(); i++) {
        string odd = expand(s, i, i);      // Odd length
        string even = expand(s, i, i + 1); // Even length
        if (odd.size() > res.size()) res = odd;
        if (even.size() > res.size()) res = even;
    }
    return res;
}

int main() {
    string s = "babad";
    cout << longestPalindrome(s);  // Output: "bab" or "aba"
}
