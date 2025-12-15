#include <bits/stdc++.h>
using namespace std;

// Solution class for LIS with reconstruction using DP
class Solution {
public:
    // Function to return the LIS as a sequence (vector)
    vector<int> longestIncreasingSubsequence(vector<int> &nums) {
        int n = nums.size();
        vector<int>dp(n,0); // dp array to store prev states
        vector<int>prev(n,-1); // to store prev index's of the arr
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i] && 1 + dp[j] > dp[i]){
                    dp[i] = 1 + dp[j] ; // is element ko LIS mai add kardo
                    prev[i] = j; // is index pe LIS ka last element kaha hai
                }
            }
        }
        // in loops ke end pe dp aur prev array ready ho jayegi
        int maxlen = 0, maxindex = 0;
        for(int i=0;i<n;i++){
            if(dp[i] > maxlen){
                maxlen = dp[i];
                maxindex = i;
            }
        }

        int cur = maxindex;
        vector<int>LIS;
        while (cur != -1)
        {
            LIS.push_back(nums[cur]);
            cur = prev[cur];
        }
        reverse(LIS.begin(),LIS.end());
        return LIS;
    }
};

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    Solution sol;
    vector<int> lis = sol.longestIncreasingSubsequence(nums);

    cout << "LIS: ";
    for (int x : lis) cout << x << " ";
    cout << endl;

    return 0;
}