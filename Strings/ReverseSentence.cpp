#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    stringstream ss(s);
    string word;
    vector<string> words;

    // Extract words ignoring extra spaces
    while (ss >> word) {
        words.push_back(word);
    }

    // Build reversed string
    string ans = "";
    for (int i = words.size() - 1; i >= 0; i--) {
        ans += words[i];
        if (i != 0) ans += " "; /// because we do not want spaces in the beinginning nor the end and want spaces only when one word ends 
        // and one word starts
        
    }

    cout << ans << endl;
    
    return 0;
}

