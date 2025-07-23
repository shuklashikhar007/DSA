// map.cpp
#include <iostream>
#include <map>
using namespace std;

/*
    C++ STL Map – Key Theory:
    1. Stores key-value pairs.
    2. Keys are unique and sorted (by default, in ascending order).
    3. Implemented using balanced BST (Red-Black Tree).
    4. Time Complexity:
        - Insertion, Deletion, Access: O(log n)
    5. map<key_type, value_type> variable;

    Types:
    - map      (ordered)
    - unordered_map (uses hash table, O(1) average time)
    - multimap (allows duplicate keys)
*/

int main() {
    map<string, int> marks;

    // Inserting values
    marks["Alice"] = 90;
    marks["Bob"] = 85;
    marks["Charlie"] = 92;

    // Iterating through map
    for (auto &pair : marks) {
        cout << pair.first << " => " << pair.second << endl;
    }

    // Accessing an element
    cout << "Marks of Alice: " << marks["Alice"] << endl;

    // Finding an element
    if (marks.find("Bob") != marks.end()) { // if the thing is found in the map this syntax will return 1 that means true and the element is present in the array 
        cout << "Bob is present.\n";
    }

    // Erasing an element
    marks.erase("Charlie");

    // Size of map
    cout << "Map size: " << marks.size() << endl;

    return 0;
}
