#include <bits/stdc++.h>
using namespace std;

int maxProductSubarray(vector<int>& nums) {
    if (nums.empty()) return 0;

    int maxProd = nums[0];
    int minProd = nums[0];
    int result = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        int curr = nums[i];

        // Store maxProd temporarily before updating
        int tempMax = max({curr, maxProd * curr, minProd * curr});
        minProd = min({curr, maxProd * curr, minProd * curr});
        maxProd = tempMax;
        result = max(result, maxProd);
    }

    return result;
}

int main() {
    vector<int> arr = {2, 3, -2, 4};
    cout << "Maximum product subarray: " << maxProductSubarray(arr) << endl;

    return 0;
}
