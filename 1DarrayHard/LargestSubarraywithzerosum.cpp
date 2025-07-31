#include<bits/stdc++.h>
using namespace std;

int maxlength(vector<int> nums, int k){
    int prefixsum = 0;
    int length  = 1;
    int maxlen = 0;
    int n = nums.size();
    // a hashmap serves as a memory in a question 
    map <int , int > mpp;
    for(int i=0;i<n;i++){
        prefixsum += nums[i];
        if(prefixsum == k){
            maxlen = i+1;
        }
        // code agar hash mai mila prefix sum to 
        int number = prefixsum - k;
        if(mpp.find(number) != mpp.end()){
            int length = i - mpp[number]; // ye length hogi is current subarray ki from the index currently - map pe value ka index 
            maxlen = max(maxlen,length);
        }
        // code agar nahi mila to  ( enter this prefix sum in the array only if we don't find it previously in the hashmap)
        if(mpp.find(prefixsum) == mpp.end()){
            mpp[prefixsum] = i;
        }
    }
    return maxlen;
}
int main(){

    vector<int> nums = {1,0,-1,1,0,-1};
    int k;
    cout << "Enter the value of sum you want  : " << endl;
    cin >> k;
    int ans = maxlength(nums,k);
    cout << "The length of the longest subarray with sum " << k << "is " << ans ;
    return 0;
}