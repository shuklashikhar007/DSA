// majority_element.cpp
#include <iostream>
#include <vector>
using namespace std;
// maths ka point if we are asked to find elements in the array having more than n/k occurence then there can be atmost k-1 such elements

int findMajorityElement(vector<int>& nums) {
    int count = 0;
    int element = 0;

    // Step 1: Find a candidate for majority element
    for (int num : nums) {
        if (count == 0) {
            element = num;
        }

        if (num == element) {
            count++;
        } else {
            count--;
        }
    }

    // Step 2: Verify if the candidate is actually a majority
    count = 0;
    for (int num : nums) {
        if (num == element) count++;
    }

    if (count > nums.size() / 2) {
        return element;
    } else {
        return -1; // No majority element
    }
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    int majority = findMajorityElement(nums);

    if (majority != -1) {
        cout << "The majority element is: " << majority << endl;
    } else {
        cout << "No majority element found in the array." << endl;
    }

    return 0;
}
