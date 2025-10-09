// ek substring mai char must appear in a continous order
#include<bits/stdc++.h>
using namespace std;
// problem - hame do string di gayi hai s and t find the smallest window in s that contains all characters of t (including duplicates)
// agar nahi hai to return ""
// approach ->
/// do hashmaps
// need -> counts frequency of each char in t
// window -> counts freq of each char in the current window of s;
string minwindow(string s, string t){
    if(t.size() > s.size())  return "";
    unordered_map<char,int> need, window;
    for(char c : t) need[c]++; // pehle ham t string ka hashmap banayege
    int have = 0, needcount = need.size();
    int left = 0;
    int minlen = INT_MAX, minstart = 0;
    for(int right = 0; right < s.size(); right++){
        char c = s[right];
        window[c]++;
        if(need.count(c) && window[c] == need[c] ){
            // ye formation condition hai 
            // agar c map mai exist karta hai aur uski freq t aur s mai same hai
            have++; // have ka count tabhi badhayege jab condition satisy hogi

        }
        // jab sare char milgaye abb window shrink karege
        while(have == needcount){
            // update min value
            if((right-left+1) < minlen){
                minlen = right - left + 1;
                minstart = left;
            }
            // jo char hatana hai hame window se
            char toremove = s[left];
            window[toremove]--;
            if(need.count(toremove) && window[toremove] < need[toremove]){
                have--;
            }
            left++;
        }
    }
    return (minlen == INT_MAX ? "" : s.substr(minstart,minlen));
}
int main(){
    string t,s;
    cin >> s >> t;
    cout << minwindow(s,t) << endl;
    return 0;
}
// after understanding do leetcode 76 
