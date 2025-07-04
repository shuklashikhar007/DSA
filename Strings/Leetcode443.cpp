// Leetcode 443: String Compression
#include <bits/stdc++.h>
using namespace std;

int compress(vector<char>& chars) {
    int i = 0; // Read pointer
    int index = 0; // Write pointer

    while (i < chars.size()) {
        char currentChar = chars[i];
        int count = 0;

        // Count occurrences of currentChar
        while (i < chars.size() && chars[i] == currentChar) {
            i++;
            count++;
        }

        // Write the character
        chars[index++] = currentChar;

        // Write the count if > 1
        if (count > 1) {
            string countStr = to_string(count);
            for (char c : countStr) {
                chars[index++] = c;
            }
        }
    }

    return index; // New length of the array
}

int main() {
    vector<char> chars = {'a','a','a','b','b','c','c','c'};
    int newLength = compress(chars);
    cout << "Compressed length: " << newLength << endl;
    cout << "Compressed characters: ";
    for (int i = 0; i < newLength; i++) {
        cout << chars[i] << " ";
    }
    cout << endl;

    return 0;
}
