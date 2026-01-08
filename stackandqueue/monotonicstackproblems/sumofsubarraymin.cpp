/*
Concept->
Use a stack to find the index of the next smaller element to the right for each position
Use another stack to find the index of the previous smaller or equal element to the left for each position
For each element, determine how many subarrays it appears in as the minimum using its NSE and PSEE indices
Calculate the contribution of each element by multiplying its value with its frequency
Add each contribution to a total sum
Return the total sum modulo 10^9 + 7
*/
#include<bits/stdc++.h>
using namespace std;
class Solution{
    private:
    // is function se hame next strictly smaller element on the right ka index milega
    vector<int> findNSE(vector<int>&arr){
        int n = arr.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1 ;i >= 0;i--){
            int curele = arr[i];
            // yaha pe stack ke andar index stored hai
            while (!st.empty() && arr[st.top()] >= arr[i])
            {   
                // keep poping till condition is true
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
        return ans;
    }
    // is function se hame previous smaller or equal elements ka index milega
    vector<int> findPSEE(vector<int> &arr){
        int n = arr.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            int curele = arr[i];
            while (!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : -1;
            st.push(i);
     
        }
        return ans;
    }
    public:
    int subarrayminsum(vector<int>&arr){
        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);

        int n = arr.size();
        int mod = 1e9 + 7;
        int sum = 0;
        for(int i=0;i<n;i++){
            int left = i - psee[i];
            int right = nse[i]  - i;
            long long freq = left*right*1LL;
            int val = (freq*arr[i]*1LL)%mod;
            sum = ( sum + val)%mod;
        }
        return sum;
    }


};
int main(){

    return 0;
}