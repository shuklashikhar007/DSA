#include <bits/stdc++.h>
using namespace std;
int setRightmostUnsetBit(int n) {
    return n | (n + 1);
}
int main() {
    int n = 10; 
    int result = setRightmostUnsetBit(n);
    cout << "Number after setting rightmost unset bit: " << result << endl; // Output: 11
    return 0;
}