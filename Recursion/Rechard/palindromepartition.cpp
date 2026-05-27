#include<bits/stdc++.h>
using namespace std;
int main(){
    
    return 0;
}
class Solution {
public:
    vector<vector<string>> ans;
    vector<string>path;
    bool palindrome(string &s, int i, int j){
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            else{
                i++;
                j--;
            }
        }
        return true;
    }
    void solve(int ind, string s, int n){
        if(ind == n){
            ans.push_back(path);
            return;
        }
        for(int i = ind; i < n; i++){
            if(palindrome(s,ind,i)){
                path.push_back(s.substr(ind,i-ind+1));
                solve(i+1,s,n);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.length();
        solve(0,s,n);
        return ans;
    }
};