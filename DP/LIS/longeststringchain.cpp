#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int LSC(vector<string> &words){
        int n = words.size(); // size of the array
        sort(words.begin(),words.end());
        vector<int>dp(n,1); // DP array
        int maxlen = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(check(words[i],words[j]) && dp[i] < dp[j] + 1 ){
                    dp[i] = dp[j]  + 1;
                }
            }
            if(dp[i] > maxlen) maxlen = dp[i];
        }
        return maxlen;
    }  
    private: 
    bool static check(string &s, string &t){
        if(s.size() != t.size()+1) return false;
        int i = 0, j = 0;
        while (i < s.size())
        {   
            if(j < t.size() && s[i] == t[j]){
                i++, j++;
            } 
            else{
                i++;
            }
        }
        // return true if the string gets empty
        if(i==s.size() && j == t.size()) return true;
        return false;
    }
};
int main(){
    vector<string> words = {"a", "ab", "abc", "abcd", "abcde"};
    // Creating an object of Solution class
    Solution sol;
    int lengthOfLongestStringChain = sol.LSC(words);
    
    cout << "The length of the Longest String Chain is: " << lengthOfLongestStringChain << endl;
    
    return 0;
}