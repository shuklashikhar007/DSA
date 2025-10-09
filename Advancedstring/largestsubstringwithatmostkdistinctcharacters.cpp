// this is a modified version of a problem we have already done on making the largest string having all distinct chars
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public :
    int lengthkdistinct(string s, int k){
        if(k == 0 || s.empty()) return 0;
        unordered_map<char,int>mpp;
        int n = s.length();
        int left = 0;
        int count = 0;
        int maxlen = 0;
        for(int right = 0;right< n;right++){
            mpp[s[right]]++;
            while(mpp.size() > k){ // agar number of distinct characters ka count k se jyada hogaya to 
                mpp[s[left]]--; // left side vale ki pehle freq kam karo hashmap se uske baad 
                // ham isse remove kardege
                // left side se window ko chota karna shuru kardege ham 
                // if character count becomes zero erase from the map;
                if(mpp[s[left]]== 0){
                    mpp.erase(s[left]);
                }
                left++; // move left pointer forward
            }
           maxlen = max(maxlen, right - left + 1); 
        }
        return maxlen;
    }
};
int main(){
    Solution sol;
    string s = "eceba";
    int k = 2;
    cout << sol.lengthkdistinct(s,k) << endl;
    return 0;
}