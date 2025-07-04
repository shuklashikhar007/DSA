// Sliding Window approach to check if any permutation of s1 is present in s2

#include <bits/stdc++.h>
using namespace std;

// Function to compare two frequency arrays
bool checkEqual(int arr1[], int arr2[]) {
    for (int i = 0; i < 26; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2) {
    int count1[26] = {0}; // Frequency array for s1
    for (char ch : s1) {
        count1[ch - 'a']++;
    }

    int windowSize = s1.length();
    int count2[26] = {0}; // Frequency array for current window in s2

    // Step 1: Process the first window of s2
    for (int i = 0; i < windowSize && i < s2.length(); i++) {
        count2[s2[i] - 'a']++;
    }

    // Step 2: Check the first window
    if (checkEqual(count1, count2)) {
        return true;
    }

    // Step 3: Process the remaining windows
    for (int i = windowSize; i < s2.length(); i++) {
        // Add new character to window
        count2[s2[i] - 'a']++;

        // Remove the character that is no longer in the window
        count2[s2[i - windowSize] - 'a']--;

        // Check if current window matches
        if (checkEqual(count1, count2)) {
            return true;
        }
    }

    // No permutation found
    return false;
}

int main() {
    string s1, s2;
    cout << "Enter the smaller string (s1): ";
    getline(cin, s1);

    cout << "Enter the larger string (s2): ";
    getline(cin, s2);

    bool found = checkInclusion(s1, s2);

    if (found) {
        cout << "✅ Permutation of s1 is present in s2" << endl;
    } else {
        cout << "❌ Permutation of s1 is NOT present in s2" << endl;
    }

    return 0;
}
