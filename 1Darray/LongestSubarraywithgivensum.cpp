// this file involves the code using hashing Basic Approach

#include <bits/stdc++.h>
using namespace std;
int longestsubarray(vector<int> &nums, int k){
    map < int , int > prefixmap;
    int prefixsum = 0; // variable to store prefix sum or running sum 
    int maxlen = 0; // variable to store max length of the subarray 

    for(int i=0;i< nums.size() ; i++){
        prefixsum += nums[i];
        // case 1 puri subarray [0 to i ] ka sum K hai 
        if(prefixsum == k){
            maxlen =  i+1;
        }
        // case -2 check if prefixsum - k was seen before in the map 
        if(prefixmap.find(prefixsum - k) != prefixmap.end() ){
            int length = i - prefixmap[prefixsum - k];
            maxlen = max(maxlen, length);
        }
        // case - 3 insert only if not already present in the map 
        if(prefixmap.find(prefixsum) == prefixmap.end()){
            prefixmap[prefixsum] = i;
        }
    }

    return maxlen;
}

int main(){
    vector<int> nums(7);
    cout << "Enter the terms of the array : ";
    for(int i=0;i<7;i++){
        cin >> nums[i];
    }
    int k = 4;

    int result = longestsubarray(nums,k);
    cout << "Length of the longest subarray with sum " << k << " is : " << result << endl;

    return 0;
}