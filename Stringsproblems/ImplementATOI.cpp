// Problem: Implement Atoi (convert string to integer)
// Handle leading spaces, optional signs, digits, overflow

#include <iostream>
#include <climits>
using namespace std;

int myAtoi(string s) {
    int i = 0, n = s.size(), sign = 1;
    long res = 0;

    // Skip leading spaces
    while (i < n && s[i] == ' ') i++;

    // Handle sign
    if (i < n && (s[i] == '-' || s[i] == '+')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    // Convert digits
    while (i < n && isdigit(s[i])) {
        res = res * 10 + (s[i] - '0');
        if (res * sign >= INT_MAX) return INT_MAX;
        if (res * sign <= INT_MIN) return INT_MIN;
        i++;
    }

    return res * sign;
}

int main() {
    string s = "   -42";
    cout << myAtoi(s);  // Output: -42
}
