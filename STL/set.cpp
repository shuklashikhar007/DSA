// set.cpp
#include <iostream>
#include <set>
using namespace std;

/*
    C++ STL Set – Key Theory:
    1. Stores only unique elements.
    2. Sorted in ascending order by default.
    3. Implemented using balanced BST (Red-Black Tree).
    4. Time Complexity:
        - Insertion, Deletion, Search: O(log n)
    5. set<datatype> variable;

    Types:
    - set          (ordered)
    - unordered_set (uses hash table, O(1) average time)
    - multiset     (allows duplicate elements)
*/

int main() {
    set<int> numbers;

    // Inserting elements
    numbers.insert(10);
    numbers.insert(5);
    numbers.insert(20);
    numbers.insert(10);  // Duplicate, will be ignored

    // Iterating through set
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // Finding an element
    if (numbers.find(5) != numbers.end()) {
        cout << "5 is present in the set.\n";
    }

    // Erasing an element
    numbers.erase(10);

    // Size of set
    cout << "Size of set: " << numbers.size() << endl;

    return 0;
}
