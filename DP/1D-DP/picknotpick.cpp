#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long solve(int i, int lastParity, vector<int>& nums, int x) {
        if (i == nums.size())
            return 0;
        long long skip = solve(i + 1, lastParity, nums, x);
        long long pick = LLONG_MIN;
        int currParity = nums[i] % 2;
        if (lastParity == 2) {
            pick = nums[i] + solve(i + 1, currParity, nums, x);
        } else {
            long long cost = nums[i];
            if (currParity != lastParity)
                cost -= x;
            pick = cost + solve(i + 1, currParity, nums, x);
        }
        return max(pick, skip);
    }
    long long maxScore(vector<int>& nums, int x) {
        return nums[0] + solve(1, nums[0] % 2, nums, x);
    }
};

int main(){
    return 0;
}