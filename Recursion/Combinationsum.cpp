/*
class Solution {
public:
    // kisi ek condition ko satisfy karne wale sare combinations banane wale questions mai it is better to declare global array's always.
    vector<vector<int>> ans;
    vector<int> curr;
    void dfs(int i, int sum, int target, vector<int>& candidates) {
        if (sum == target) {
            ans.push_back(curr);
            return;
        }
        if (sum > target || i == candidates.size()) {
            return;
        }
        curr.push_back(candidates[i]);
        dfs(i, sum + candidates[i], target, candidates);
        curr.pop_back();  
        dfs(i + 1, sum, target, candidates);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(0, 0, target, candidates);
        return ans;
    }
};





*/