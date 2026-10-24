#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // bahut hi amazing aur accha question hai ye 
    // for a window to be valid we have ->
    // max poss value jo min le sakta hai mini + k = a
    // min poss value jo max le sakta hai maxi - k = b
    // for a valid window jisme sari value equal ho jaye
    // a >= b hona chaiye
    // mini + k >= maxi - k
    // maxi - mini <= 2*k -> ek valid subarray ki condition ye hogi
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int start = 0, ans = 0;
        for(int i=0; i<nums.size(); i++){
            // here nums[i] = maxi and nums[start] = mini
            // while window is not vaild increase the current minimum 
            while(nums[i]-nums[start] > 2*k)
                start++;
            // the current window i.e. [start ... i] is valid so consider it
            ans = max(ans,i-start+1);
        }
        return ans;
    }
};
int main(){

    return 0;
}