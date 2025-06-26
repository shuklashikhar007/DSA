#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>  // For character functions
using namespace std;

int main() {
    // Initialization
    string s1 = "Hello";
    string s2 = "World";
    string s3 = s1 + " " + s2;

    cout << "Concatenated: " << s3 << endl;

    // Access characters
    cout << "First character: " << s3[0] << endl;

    // Length
    cout << "Length: " << s3.length() << endl;

    // Substring
    cout << "Substring (0, 5): " << s3.substr(0, 5) << endl;

    // Find ******
    size_t pos = s3.find("World");
    if (pos != string::npos)
        cout << "'World' found at index: " << pos << endl;

    // Comparison
    if (s1 == "Hello")
        cout << "s1 is equal to 'Hello'" << endl;

    // Append
    s1.append("!!");
    cout << "After append: " << s1 << endl;

    // Insert
    s1.insert(1, "ey");
    cout << "After insert: " << s1 << endl;

    // Erase
    s1.erase(1, 2);
    cout << "After erase: " << s1 << endl;

    // Replace
    s1.replace(0, 5, "Hi");
    cout << "After replace: " << s1 << endl;

    // clear & empty
    string temp = "Data";
    temp.clear();
    cout << "Is temp empty? " << (temp.empty() ? "Yes" : "No") << endl;

    // stoi and to_string
    string numStr = "12345";
    int num = stoi(numStr); // stoi stands for string to int -> converting string to integer using a inline function 
    cout << "String to int: " << num << endl;

    int val = 99;
    string valStr = to_string(val); // converting a number to a string using a inline function.
    cout << "Int to string: " << valStr << endl;

    // Sorting
    string sortStr = "dcba";
    sort(sortStr.begin(), sortStr.end()); // to sort a string in ascending order form index (from , to); be default in ascending order 
    cout << "Sorted string: " << sortStr << endl;

    // Reverse
    reverse(sortStr.begin(), sortStr.end());
    cout << "Reversed string: " << sortStr << endl;

    // Character functions
    char ch = 'G';
    cout << ch << " is lowercase? " << (islower(ch) ? "Yes" : "No") << endl;
    cout << ch << " to lower: " << (char)tolower(ch) << endl;

    // Range-based loop
    string sample = "Loop";
    cout << "Characters in '" << sample << "': ";
    for (char c : sample) cout << c << " "; 
    cout << endl;

    // Multiline string (Raw string)
    string multiline = R"(Line1
    Line2
    Line3)";
    cout << "Multiline string:\n" << multiline << endl;

    // getline usage to take input of full sentences 
    string line;
    cout << "Enter a full sentence: ";
    getline(cin, line); // getline(cin,line);
    cout << "You entered: " << line << endl;

    return 0;
}

