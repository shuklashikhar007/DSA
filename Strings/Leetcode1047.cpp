#include <iostream>
using namespace std;

string removeDuplicates(string s) {
    string answer = ""; // This will store our final result

    for (int i = 0; i < s.length(); i++) {
        char current = s[i];

        // If answer is not empty and last character is same as current
        if (!answer.empty() && answer[answer.length() - 1] == current) {
            answer.pop_back(); // remove last character because it's same as the current char 
        } else {
            answer += current; // add current character
        }
    }

    return answer;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    string result = removeDuplicates(s);
    cout << "After removing duplicates: " << result << endl;

    return 0;
}

/*
Input: abbaca

Step-by-step:
'a' → answer = "a"
'b' → answer = "ab"
'b' → same as last → remove → answer = "a"
'a' → same as last → remove → answer = ""
'c' → answer = "c"
'a' → answer = "ca"

Final answer = "ca"

*/

