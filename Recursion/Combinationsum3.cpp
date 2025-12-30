/*
class Solution {
public:
    vector<int>a = {1,2,3,4,5,6,7,8,9};
    vector<vector<int>> ans;
    vector<int> cur;
    void g(int ind, int rsum, int cnt, int goal) {
        // galti yaha thi jab rsum == goal tab count exact zero hona chaiye
        if (rsum == goal && cnt == 0) {
            ans.push_back(cur);
            return;
        }
        // in teeno mai se ek bhi case hai to return mardege ham
        if (ind == a.size() || rsum > goal || cnt <= 0) {
            return;
        }
        cur.push_back(a[ind]);
        g(ind + 1, rsum + a[ind], cnt - 1, goal);
        cur.pop_back();
        g(ind + 1, rsum, cnt, goal);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        g(0, 0, k, n);
        return ans;
    }
};







*/