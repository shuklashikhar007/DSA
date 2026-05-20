#include<bits/stdc++.h>
using namespace std;
int main(){
    
}
class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n = s.length();
        int l = 0, r = n - 1;
        int cnt = 0;
        int cent = -1;
        while (l < r) {
            // already matched
            if (s[l] == s[r]) {
                l++;
                r--;
                continue;
            }
            // search matching char for s[r]
            int k = l + 1;
            for (; k < r; k++) {
                if (s[k] == s[r]) {
                    break;
                }
            }
            // no matching character found
            // this is center character
            if (k == r) {
                cent = r;
                r--; // abhi ke liye isko ignore kardiya hai hamne 
                continue;
            }
            // bubble matching char toward left
            for (int j = k; j > l; j--) {
                swap(s[j], s[j - 1]);
                cnt++;
            }
            l++;
            r--;
        }
        // move center char to actual center
        if (cent != -1) {
            cnt += abs(cent - n / 2);
        }
        return cnt;
    }
};