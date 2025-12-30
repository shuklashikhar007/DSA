/*
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;

    void f(int ind, int sum, vector<int>& a, int target) {
        if (sum == target) {
            ans.push_back(cur);
            return;
        }
        if (sum > target || ind == a.size()) return;
        // pick wale casesmai sare possible picks ho jayenge so we skip duplicates only in the case of not pick
        cur.push_back(a[ind]);
        f(ind + 1, sum + a[ind], a, target);
        cur.pop_back();
        while (ind + 1 < a.size() && a[ind] == a[ind + 1])
            ind++;
        f(ind + 1, sum, a, target);
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        f(0, 0, nums, target);
        return ans;
    }
};










*/