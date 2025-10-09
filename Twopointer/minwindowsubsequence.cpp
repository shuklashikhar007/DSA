// find the smallest substring in s which contains t as a subsequence (order preserved ) not necessarily continous
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindowSubsequence(string S, string T) {
        int n = S.size(), m = T.size();
        int minLen = INT_MAX;
        string res = "";

        for (int i = 0; i < n; i++) {
            int j = 0;
            // Find the subsequence starting from i
            while (i < n) {
                if (S[i] == T[j]) j++;
                if (j == m) break; // found full T
                i++;
            }
            if (j < m) break; // no more subsequences possible

            // Backtrack to find start index
            int end = i;
            j = m - 1;
            while (i >= 0) {
                if (S[i] == T[j]) j--;
                if (j < 0) break;
                i--;
            }

            int start = i;
            if (end - start < minLen) {
                minLen = end - start;
                res = S.substr(start, end - start + 1);
            }

            // Move to next possible start
            i = start + 1;
        }

        return res;
    }
};
int main(){
    Solution sol;
    string s,t;
    cin >> s >> t;
    cout << sol.minWindowSubsequence(s,t)<< endl;
    return 0;
}