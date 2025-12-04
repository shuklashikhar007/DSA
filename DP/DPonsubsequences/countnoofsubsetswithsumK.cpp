#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to count subsets that sum up to target
    int countSubsets(vector<int>& nums, int target) {
        // Initialize dp table with -1 (uncomputed states)
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
        return solve(nums.size() - 1, target, nums, dp);
    }

private:
    // Recursive helper with memoization
    int solve(int index, int target, vector<int>& nums, vector<vector<int>>& dp) {
        // Base case: if target is 0, we found a valid subset
        if (target == 0) return 1;

        // Base case: if we are at index 0, check if nums[0] equals target
        if (index == 0) return (nums[0] == target ? 1 : 0);

        // If already computed, return from dp
        if (dp[index][target] != -1) return dp[index][target];

        // Case 1: Exclude current element
        int notTake = solve(index - 1, target, nums, dp);

        // Case 2: Include current element (if it is not greater than target)
        int take = 0;
        if (nums[index] <= target) {
            take = solve(index - 1, target - nums[index], nums, dp);
        }

        // Store result in dp and return
        return dp[index][target] = take + notTake;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 3};
    int target = 6;
    Solution obj;
    cout << obj.countSubsets(nums, target) << endl;
    return 0;
}