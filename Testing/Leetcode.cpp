#include <iostream>
#include <string>
using namespace std;

int numerology(string num) {
    if (num.length() == 1) { // base case
        return stoi(num);
    }

    int value = 0;
    for (int i = 0; i < num.length(); i++) {
        value += num[i] - '0'; // convert char to digit agar add karne hai string ke digits to 
    }

    string pass = to_string(value);
    return numerology(pass); // return the result of recursion
}

int main() {
    int nums;
    cin >> nums;
    string number = to_string(nums);
    int final = numerology(number);
    cout << "The final ans is : " << final << endl;
    return 0;
}
