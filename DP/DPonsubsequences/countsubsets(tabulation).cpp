#include <bits/stdc++.h>
using namespace std;
// mera doubt clear
// we start i from 1 in outer loop beacuse in dp formula we use i - 1 so we cannot start i from 0 but we need to start t from 0 in inner loop because 
// t = 0 is used in the reccurence formula

int subsets(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    // Base case: sum = 0 → 1 subset (empty set)
    for (int i = 0; i < n; i++)
        dp[i][0] = 1;

    // Base case: using only nums[0]
    if (nums[0] <= target)
        dp[0][nums[0]] = 1;

    for (int i = 1; i < n; i++) {
        for (int t = 0; t <= target; t++) {
            int nottake = dp[i - 1][t];
            int take = 0;

            if (nums[i] <= t)
                take = dp[i - 1][t - nums[i]];

            dp[i][t] = nottake + take;
        }
    }

    return dp[n - 1][target];
}

int main() {
    vector<int> nums = {1, 2, 3, 3};
    int target = 6;
    int ans = subsets(nums, target);
    cout << ans;
    return 0;
}
