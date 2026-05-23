//
#include<bits/stdc++.h>
using namespace std;
// yahi logic we can apply in subarray itself 
class Solution {
public:
    int atmost(vector<int>&nums, int k){
        int n = nums.size();
        unordered_map<int,int>mpp;
        // ek window ke andar ek num ki freq kya hai 
        int l = 0, r = 0, cnt = 0;
        for(r = 0; r < n ; r++){
            if(mpp[nums[r]] == 0){
                k--; // r wale ki freq 0 hai iska matoab ye hai ki jo naya char aya hai uski freq 0 hai poehle 
                // se to no of distinct slots have decreased
            }
            mpp[nums[r]]++; // iski freq badha di
            while(k<0){
                // if no of distinct ka count neg ho gya matlab no of distinct in window are more than req 
                // to hame left side se kam karne chiaye 
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0){
                    k++; // isko hatane ke badd freq 0 matlab ek distinct remove haa hai yaha se
                }
                l++;
            }
            // yaha agye matlab no of distinct == k
            cnt += (r - l + 1);
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // exact k chaiye to yaha ham wahi concept lagayenge 
        // exact k = atmost (k) - atmost(k-1)
        int n = nums.size();
        int l = 0, r = n-1;
        int ans = atmost(nums,k) - atmost(nums,k-1);
        return ans;
    } 
};
int main(){

    return 0;
}