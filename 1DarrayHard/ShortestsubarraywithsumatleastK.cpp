// Ye ek bahut accha question hai actually mai 
// pehli bar deque ka use kiya hamne yaha pe
/*
class Solution {
public:
    using ll = long long;
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> prefix(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1] = prefix[i] + nums[i];
        }
        deque<int> dq;
        int ans = n+1;
        for(int j=0;j<=n;j++){
            // yaha pe jo jth index hai usse ek bar subarray ban gayi agar to iske baad wese bhi isse lambi hi banegi
            while(!dq.empty() && prefix[j] - prefix[dq.front()] >= k){
                ans = min(ans, j - dq.front());
                dq.pop_front();
            }
            // choti prefix sum value back se mili to wo abb kisi kaam ki nahi since we need shortest 
            while(!dq.empty() && prefix[j] <= prefix[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(j);
        }
        return ans == n+1 ? -1 : ans;
    }
};





*/