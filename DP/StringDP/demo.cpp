// Finding the longest common subsequence is the most important and  crucial topic in string DP
#include<bits/stdc++.h>
using namespace std;
int LCS(string a, string b, int ind1, int ind2){
    // base case
    if(ind1 < 0 || ind2 < 0){
        return 0; // iska matlab dono mai se koi ek string finish hogayi hai
    }
    if(a[ind1] == b[ind2]){ // agar chars match hue to 
        return 1 + LCS(a,b,ind1-1,ind2-1);
    }
    // nahi match kiye to 
    return max(LCS(a,b,ind1-1,ind2),LCS(a,b,ind1,ind2-1));
}
int main(){
    string a,b;
    cin >> a >> b;
    int ans = LCS(a,b, a.length()-1,b.length()-1);
    cout << "THE length of LCS is : " << ans << endl;
    return 0;
}



