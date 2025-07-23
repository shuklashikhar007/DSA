// this approach will work only if the array contains only positive numbers and fails if it contains negative numbers.
#include <iostream>
#include <vector>
using namespace std; 
int longestSubarrayWithSumK(vector<int>& nums, int K) {
    int left = 0, right = 0;
    int sum = nums[0];
    int maxLen = 0;
    int n = nums.size();

    while (right < n) {
        // Shrink the window from the left if sum > K
        while (left <= right && sum > K) {
            sum -= nums[left];
            left++;
        }

        // If current window sum == K, update maxLen
        if (sum == K) {
            maxLen = max(maxLen, right - left + 1);
        }

        // Move right pointer forward
        right++;
        if (right < n) {
            sum += nums[right];
        }
    }

    return maxLen;
}

int main() {
    vector<int> nums = {1, 2, 1, 1, 1};
    int K = 3;

    int result = longestSubarrayWithSumK(nums, K);
    cout << "Length of longest subarray with sum " << K << " is: " << result << endl;

    return 0;
}
