#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> threeSum(vector <int> nums){
    vector<vector<int>>result;
    int n = nums.size();
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        // skip duplicate elements for each value of i 
        if(i>0 && nums[i] == nums[i-1]){
            continue;
        }
        int j = i+1;
        int k = n-1;
        while(j<k){
            int sum = nums[i] + nums[j] + nums[k];
            if(sum < 0){
                j++; // if sum is less than zero we need a larger number so we move ahead 
            }
            else if(sum > 0){
                k--; // if sum is positive we need a smaller number move back 
            }
            else{
                // Triplet is found sum == 0
                vector<int>triplet = {nums[i],nums[j],nums[k]};
                result.push_back(triplet);
                j++;
                k--;
            }
            // skip the duplicates next to the jth and kth index 
            while(j<k && nums[j] == nums[j-1]){
                j++;
            }
            while(j<k && nums[k] == nums[k-1]){
                k--;
            }
        }
    }
    return result;
}
int main(){
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = threeSum(nums); // store the triplets in a 2D array 
    for (auto triplet : ans) {
        for (auto num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}