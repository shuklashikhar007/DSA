// longest palindromic subsequence
// to find the longest palindromic subsequence of a string S1
// APPLY THE LOGIC -> LCS(s1, rev(s1));
#include<bits/stdc++.h>
using namespace std;
string reverse(string a){
    string s;
    for(int i=a.length()-1;i>=0;i--){
        s += a[i];
    }
    return s;
}
int LCS(string a, string b,int ind1 ,int ind2, vector<vector<int>> &dp){
    // base case
    if(ind1 < 0 || ind2 < 0) return 0;
    if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
    if(a[ind1] == b[ind2]){ // matlab match hogaya
        return 1 + LCS(a,b,ind1-1,ind2-1,dp);
    }
    return dp[ind1][ind2] = max(LCS(a,b,ind1-1,ind2,dp),LCS(a,b,ind1,ind2-1,dp));
}
int main(){
    string a;
    cin >> a;
    string b = reverse(a);
    vector<vector<int>> dp(a.length(), vector<int>(b.length(),-1)); // dp array for memo
    int ans = LCS(a,b,a.length()-1,b.length()-1,dp);
    cout << ans << endl;
    return 0;
}
// is they ask min no of deletion  to make palindrome then it will be n - len(LCS);