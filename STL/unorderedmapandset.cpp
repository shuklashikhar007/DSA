#include<bits/stdc++.h>
using namespace std;
bool unique(vector<int> &arr, int n){

    unordered_map<int , int> freq;
    for(int num : arr){
        freq[num]++;
    }

    unordered_set<int> seen;
    for(auto &[key, value] : freq){
        if(seen.count(value)){
            return false;
        }
        seen.insert(value);
    }

    return true;
}
int main(){

    vector<int> arr = {1,2,2,1,1,3};
    int ans = unique(arr,6);



    return 0;
}