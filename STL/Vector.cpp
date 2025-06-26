#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v; // declares an empty vector of integers

    // Adding elements
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    // Accessing elements
    cout << "First element: " << v[0] << endl;

    vector<int> v1;                  // empty vector
    vector<int> v2(5);               // 5 elements, default-initialized (0)
    vector<int> v3(5, 100);          // 5 elements, each of value 100
    vector<int> v4 = {1, 2, 3, 4};   // initializer list

    v.push_back(5);   // Add to end
    v.pop_back();     // Remove last element
    cout << v[2];        // No bounds checking
    cout << v.at(2);     // Safer, with bounds checking

    v.size();      // Number of elements
    v.capacity();  // Current allocated size
    v.empty();     // Check if vector is empty

    for (int i = 0; i < v.size(); i++)
    cout << v[i] << " ";
    for (int x : v)
    cout << x << " ";
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    cout << *it << " ";
    v.clear();      // removes all elements
    v.resize(10);   // resize vector to 10 elements (adds 0s or truncates)

    return 0;
}