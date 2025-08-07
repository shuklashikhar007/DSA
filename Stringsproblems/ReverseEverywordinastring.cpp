// solve this question using string stream built in fcuntion.
// Problem: Reverse each word in a string individually
// Approach: Use two pointers to reverse each word in-place

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string reverseWords(string s) {
    int n = s.length(), i = 0;
    while (i < n) {
        while (i < n && s[i] == ' ') i++;
        int start = i;
        while (i < n && s[i] != ' ') i++;
        reverse(s.begin() + start, s.begin() + i);
    }
    return s;
}

int main() {
    string s = "Let's take LeetCode contest";
    cout << reverseWords(s);  // Output: "s'teL ekat edoCteeL tsetnoc"
}
