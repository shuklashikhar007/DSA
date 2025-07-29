#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> nums) {
    int n = nums.size();
    set<vector<int>> st; // to store unique triplets 

    for (int i = 0; i < n; i++) {
        unordered_set<int> hashset; // hashset to look out for the third element 
        for (int j = i + 1; j < n; j++) {
            int third = -(nums[i] + nums[j]);
            if (hashset.find(third) != hashset.end()) { 
                vector<int> triplet = {nums[i], nums[j], third}; // agar third mil gya to form a triplet and enter it into the set 
                sort(triplet.begin(), triplet.end());
                st.insert(triplet);
            }
            hashset.insert(nums[j]); // otherwise nahi mila third to place it in the hashset for the future use 
        }
    }

    vector<vector<int>> result(st.begin(), st.end()); // convert the set into a 2D result vector.
    return result;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = threeSum(nums);

    for (auto triplet : ans) {
        for (auto num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
