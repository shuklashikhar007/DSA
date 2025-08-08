// Problem: Sum of Beauty of All Substrings
// Beauty = maxFreq - minFreq of characters in substring
// Approach: Brute-force with frequency map

#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;
int beautySum(string s) {
    int n = s.size(), result = 0;
    for (int i = 0; i < n; i++) {
        vector<int> freq(26, 0);
        for (int j = i; j < n; j++) {
            freq[s[j] - 'a']++;
            int maxF = 0, minF = INT_MAX;
            for (int f : freq){
                if (f == 0) continue;
                maxF = max(maxF, f);
                minF = min(minF, f);
            }
            result += maxF - minF;
        }
    }
    return result;
}

int main() {
    string s = "aabcb";
    cout << beautySum(s);  // Output: 5
}
