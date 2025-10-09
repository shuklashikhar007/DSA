#include<bits/stdc++.h>
using namespace std;
int longestones(vector<int>&nums , int k){
    int left = 0;
    int zeros = 0;
    int maxlen = 0;
    for(int right = 0; right < nums.size(); right++){
        if(nums[right] == 0) zeros++;
        while(zeros > k){
            if(nums[left] == 0){
                zeros--;
            }
            left++;
        }
        maxlen = max(maxlen,right-left+1);
    }
    return maxlen;
}
int main(){
    vector<int>nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    cout << longestones(nums,k) << endl;
    return 0;
}