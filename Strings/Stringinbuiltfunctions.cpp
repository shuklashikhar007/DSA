#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Custom comparator: Even numbers before odd, then ascending
bool evenFirst(int a, int b) {
    if (a % 2 == 0 && b % 2 != 0) return true;
    if (a % 2 != 0 && b % 2 == 0) return false;
    return a < b;
}

// Comparator for sorting pairs by second value
bool sortBySecond(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {

    // 1. Sorting Array (Ascending)
    int arr[] = {5, 3, 1, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n);
    cout << "Array sorted in ascending order:\n";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n\n";

    // 2. Sorting Vector (Descending)
    vector<int> vec = {5, 1, 4, 2, 3};
    sort(vec.begin(), vec.end(), greater<int>());
    cout << "Vector sorted in descending order:\n";
    for (int x : vec) cout << x << " ";
    cout << "\n\n";

    // 3. Sorting a string
    string s = "programming";
    sort(s.begin(), s.end());
    cout << "Sorted string: " << s << "\n\n";

    // 4. Custom comparator: Even numbers first
    vector<int> evens = {3, 1, 4, 2, 5};
    sort(evens.begin(), evens.end(), evenFirst);
    cout << "Even numbers first:\n";
    for (int x : evens) cout << x << " ";
    cout << "\n\n";

    // 5. Sorting vector of pairs by second element
    vector<pair<int, int>> vp = {{1, 5}, {2, 3}, {3, 2}};
    sort(vp.begin(), vp.end(), sortBySecond);
    cout << "Vector of pairs sorted by second element:\n";
    for (auto p : vp) cout << "(" << p.first << ", " << p.second << ") ";
    cout << "\n\n";

    // 6. Sorting array in descending order
    int arrDesc[] = {4, 1, 3, 5, 2};
    sort(arrDesc, arrDesc + 5, greater<int>());
    cout << "Array sorted in descending order:\n";
    for (int i = 0; i < 5; i++) cout << arrDesc[i] << " ";
    cout << "\n\n";

    return 0;
}
