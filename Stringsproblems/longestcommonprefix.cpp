// Problem: Find the longest common prefix among all strings in the array
// Correct Approach: Compare each string with the prefix and shorten it as needed

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    // Assume the first string is the prefix
    string prefix = strs[0];

    // Compare with all other strings
    for (int i = 1; i < strs.size(); i++) {
        int j = 0;
        // Compare characters of current prefix and current string
        while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j]) {
            j++;
        }
        // Shorten the prefix
        prefix = prefix.substr(0, j);

        // If at any point prefix is empty, break early
        if (prefix == "") break;
    }

    return prefix;
}

int main() {
    vector<string> strs = {"flower", "flow", "flight", "flood"};

    string result = longestCommonPrefix(strs);

    if (!result.empty())
        cout << "Longest Common Prefix: " << result << endl;
    else
        cout << "No common prefix found." << endl;

    return 0;
}
