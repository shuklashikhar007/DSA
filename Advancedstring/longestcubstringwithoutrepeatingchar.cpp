#include<bits/stdc++.h>
using namespace std;
int find(string s){
    int n = s.length();
    int longest = INT_MIN;
    int left = 0, right = n;
    unordered_map<char,int>mpp;
    for(right = 0;right<n;right++){
        char c = s[right];
        if(mpp.count(c)   && mpp[c] >= left){
            // matlab ye char pehle bhi a chuka hai 
            left = mpp[c] + 1; // window ko chota kar diya
        }
        mpp[c] = right; // update the last seen index of that particular char
        longest = max(longest, right - left + 1);
    }
    return longest;
}
int main(){
    string s;
    cin >> s;
    int longest = find(s);
    cout << longest << endl;
    return 0;
}