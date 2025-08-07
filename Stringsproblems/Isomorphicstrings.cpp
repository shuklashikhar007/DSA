// Problem: Determine if two strings s and t are isomorphic
// Approach:
// Two strings are isomorphic if the characters in s can be replaced to get t,
// preserving order and 1-to-1 character mapping.

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool isIsomorphic(string s, string t) {
    if (s.length() != t.length()) return false;

    // Mapping from s to t and t to s to ensure 1-to-1 mapping
    unordered_map<char, char> map1, map2;

    for (int i = 0; i < s.length(); i++) {
        char c1 = s[i], c2 = t[i];

        // Check if there's an existing mapping from s -> t
        if (map1.count(c1)) {
            if (map1[c1] != c2) return false;
        } else {
            map1[c1] = c2;
        }

        // Check if there's an existing mapping from t -> s (inverse)
        if (map2.count(c2)) {
            if (map2[c2] != c1) return false;
        } else {
            map2[c2] = c1;
        }
    }

    return true;
}

int main() {
    string s = "egg", t = "add";
    if (isIsomorphic(s, t))
        cout << "Yes, the strings are isomorphic.\n";
    else
        cout << "No, the strings are not isomorphic.\n";

    return 0;
}
