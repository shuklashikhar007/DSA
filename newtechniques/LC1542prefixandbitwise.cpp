// optimized way to find if we can rearrage the letters or numbers of s subarray to from a palindrome from it 
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestAwesome(string s) {
        int n = s.size();
        vector<int> first(1024, n); // 2^10 masks
        first[0] = -1;
        int mask = 0;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            // toggle parity of current digit
            mask ^= (1 << (s[i] - '0')); // ye yaha tak ka prefix hai 
            // Case 1: all digits even
            ans = max(ans, i - first[mask]);
            // Case 2: exactly one digit odd
            for(int bit = 0; bit < 10; bit++) {
                int newMask = mask ^ (1 << bit);
                ans = max(ans, i - first[newMask]);
            }
            // store earliest occurrence
            first[mask] = min(first[mask], i);
        }
        return ans;
    }
};
int main(){
    return 0;
}