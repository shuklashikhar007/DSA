// Problem: Sort Characters by Frequency
// Approach: Count frequencies using unordered_map, then use a max heap to sort characters by frequency.

#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

string frequencySort(string s) {
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;

    // Max heap to get characters with highest frequency first
    priority_queue<pair<int, char>> maxHeap;
    for (auto &p : freq) {
        maxHeap.push({p.second, p.first});
    }

    string result;
    while (!maxHeap.empty()) {
        auto [count, ch] = maxHeap.top(); maxHeap.pop();
        result.append(count, ch);  // append 'ch' count times
    }

    return result;
}

int main() {
    string s = "tree";
    cout << frequencySort(s);  // Output could be "eetr" or "eert"
}
