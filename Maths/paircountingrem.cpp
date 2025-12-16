#include<bits/stdc++.h>
using namespace std;
// Function to find the ans
long long countpairs(vector<int>&a, int x){
    unordered_map<int,long long> cnt;
    long long ans = 0;
    for(int v : a){
        int r = ((v%x) + x)%x; // to handle negative and small numbers
        int need = (x-r)%x; // the number we need to pair up with remainder r
        ans += cnt[need]; // add how many times that number was seen 
        cnt[r]++; // store the freq of this remained
    }
    return ans;
}
int main(){
    // the problem is that we have to find no of pairs in an array a such that i < j and (arr[i] + arr[j]) % x == 0 where x is some given number
    // Core maths logic ->
    // (arr[i] + arr[j]) % x == 0
    // (arr[i] % x + arr[j] % x) % x == 0
    // So only remainder matters
    /*
    Step-by-step Optimal Strategy
    Compute remainder of each element modulo x
    Maintain frequency of remainders seen so far
    For each remainder r, we need:
    (r + needed) % x == 0
    ⇒ needed = (x - r) % x    
    Count how many such needed have appeared earlier
    this ensures i < j automatically

    */

    return 0;
}