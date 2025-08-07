// Problem: Convert Roman Numeral to Integer
// Approach: Scan right to left and subtract if smaller precedes larger

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> roman = {
        {'I', 1}, {'V', 5}, {'X', 10},
        {'L', 50}, {'C', 100},
        {'D', 500}, {'M', 1000}
    };
    int total = 0, prev = 0;

    for (int i = s.size() - 1; i >= 0; i--) {
        int val = roman[s[i]];
        if (val < prev) total -= val;
        else total += val;
        prev = val;
    }
    return total;
}

int main() {
    string roman = "MCMXCIV";
    cout << romanToInt(roman);  // Output: 1994
}
