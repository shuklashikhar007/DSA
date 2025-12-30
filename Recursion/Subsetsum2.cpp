/*

class Solution {

public:
vector<vector<int>> ans;
vector<int> curr;
    void f(int ind , vector<int>&a , int n){
        if(ind == n){
            ans.push_back(curr);
            return;
        }
        curr.push_back(a[ind]);
        f(ind+1,a,n);
        curr.pop_back(); // backtracking
        // abb non pick wale case mai duplicate hata denge
        while(ind < n-1 && a[ind] == a[ind+1]) ind++;
        f(ind+1 ,a,n);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        // duplicate avoid karne wale case wealways sort thearray to make sure the duplicates
        // come adjacent to each other
        f(0,nums,n);
        return ans;
    }
};


*/