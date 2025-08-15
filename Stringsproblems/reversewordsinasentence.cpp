#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "I love learning C++ and problem solving";
    
    stringstream ss(s);   // create stringstream from the string
    string word;
    vector<string> words;

    while (ss >> word) {   // extract each word separated by whitespace
        words.push_back(word);
    }
    // print the vector to verify
    for (auto &w : words) {
        cout << w << endl;
    }
    return 0;
}
