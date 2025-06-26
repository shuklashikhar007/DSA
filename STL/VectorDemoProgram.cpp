#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {10, 20, 30};

    nums.push_back(40);
    nums.push_back(50);

    cout << "Elements: ";
    for (int num : nums)
        cout << num << " ";

    nums.pop_back(); // removes 50

    cout << "\nAfter pop_back: ";
    for (int num : nums)
        cout << num << " ";

    return 0;
}
