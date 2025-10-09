// how to find the length of the longest unique substring from a string and output it
#include<bits/stdc++.h>
using namespace std;
int length(string s){
    int left = 0;
    int right = 0;
    int maxlen =0;
    unordered_map<char,int>lastindex;

    for(int right = 0; right < s.size() ; right++){
        char c = s[right];
        if(lastindex.count(c) && lastindex[c] >= left){
            // matlab last time jaha pe ye char dikha tha wo current window mai lie karta hai ki nahi
            // to check this lastindex[c] >= left
            left = lastindex[c] + 1; // window choti kardo
        }
        lastindex[c] = right; // update the last seen index
        maxlen = max(maxlen, right - left + 1);
    }   
    return maxlen;
}
int main(){
    string s;
    cin >> s;
    cout << length(s) << endl;
    return 0;
}