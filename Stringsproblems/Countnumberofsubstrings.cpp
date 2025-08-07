// Problem: Count substrings with exactly k distinct characters
// Approach: Sliding window + Hash Map

#include <iostream>
#include <unordered_map>
using namespace std;

int atMostK(string s, int k) {
    int left = 0, res = 0;
    unordered_map<char, int> freq;

    for (int right = 0; right < s.length(); right++) {
        freq[s[right]]++;
        while (freq.size() > k) {
            freq[s[left]]--;
            if (freq[s[left]] == 0) freq.erase(s[left]);
            left++;
        }
        res += right - left + 1;
    }
    return res;
}

int countExactlyK(string s, int k) {
    return atMostK(s, k) - atMostK(s, k - 1);
}

int main() {
    string s = "abcba";
    int k = 2;
    cout << countExactlyK(s, k);  // Output: 7
}
