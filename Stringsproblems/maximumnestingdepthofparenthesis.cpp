// Problem: Maximum Nesting Depth of Parenthesis
// Approach: Track current and max depth while scanning the string

#include <iostream>
#include <string>
using namespace std;

int maxDepth(string s) {
    int depth = 0, maxDepth = 0;
    for (char c : s) {
        if (c == '(') {
            depth++;
            maxDepth = max(maxDepth, depth);
        } else if (c == ')') {
            depth--;
        }
    }
    return maxDepth;
}

int main() {
    string s = "(1+(2*3)+((8)/4))+1";
    cout << maxDepth(s);  // Output: 3
}
