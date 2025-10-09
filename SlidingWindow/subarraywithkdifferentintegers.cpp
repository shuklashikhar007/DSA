// Subarray with k different integers a good subarray is defined as a continous subarray that contains exactly k distinct integers
// yaha bhi wahi atmost k wali strategy lagayege
// pehle ek function bana lo atmost() uske baad hamara answer hoga 
// atmost(k) - atmost(k-1)
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int atmostk(vector<int>& nums, int k){
            unordered_map<int,int> freq;
            int left = 0, count = 0;
            // array ko right pointer se traverse karege
            for(int right = 0; right < nums.size(); right ++){
                // agar naya unique element agaya to decrease the value of k
                if(freq[nums[right]] == 0){
                    k--;
                }
                freq[nums[right]]++; // increase freq of current element
                // agar distinct ka count k se jyada chala gaya to restore the condition 
                while(k<0){
                    freq[nums[left]]--;
                    if(freq[nums[left]] == 0){ // matlab pure tarike se hath chuka hai ye element 
                        k++;
                    }
                    left++;
                }

                // count all the subarray's ending at the current right 
                count += (right - left + 1);
            }
            return count;
        }   
};
int main(){
    Solution sol;
    vector<int> nums = {1,2,1,2,3};
    int k = 2;
    cout << sol.atmostk(nums,k) - sol.atmostk(nums,k-1) << endl;
    return 0;
}