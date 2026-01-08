// ye 4 functions samajh lo stack khatam
/*
    Conceptual approach
Find the index of the next smaller element to the right for each element using NSE logic
Find the index of the previous smaller or equal element to the left using PSEE logic
Find the index of the next greater element to the right for each element using NGE logic
Find the index of the previous greater or equal element to the left using PGEE logic
Use NSE and PSEE to calculate the total contribution of each element as the minimum in subarrays
Use NGE and PGEE to calculate the total contribution of each element as the maximum in subarrays
Subtract the total of subarray minimums from the total of subarray maximums
Return the result as the sum of ranges of all subarrays
*/
#include<bits/stdc++.h>
using namespace std;
// is code mai stack ke 4 sabse important function hai
// function to find the next smaller element on the right
vector<int> findNSE(vector<int> &arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
           // jab tak true hai ye pop karte raho
           st.pop();
        }
        ans[i] = st.empty() ? n : st.top();
        // agar koi element nahi mila smaller to put n basically outside of the array since we can choose 
        // all index from here till n-1 kyoki ye hai case mai minimum hi hoga
        st.push(i);
    }
    return ans;
}
// function to find the index of the next greater element on the right 
vector<int> findNGE(vector<int>&arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        while (!st.empty() && arr[st.top()] <= arr[i])
        {
            st.top();
        }
        ans[i] = st.empty() ? st.top() : n;
        st.push(i);
    }
    return ans;
}
vector<int> findPSEE(vector<int>&arr){
    int n = arr.size();
    vector<int>ans(n);
    stack<int>st;
    for(int i=0;i<n;i++){
        int curele = arr[i];
        while (!st.empty() && arr[st.top()] > curele)
        {
            st.pop();
        }
        ans[i] = st.empty() ? st.top() : -1;
        st.push(i);
        /*
        why - 1push when nothing found
        -1 means “you are the smallest seen so far, so you can expand all the way to index 0.
        index -{-1} mean we can take all index from 0 to the current that means index + 1
        */
    }
    return ans;
}
vector<int> findPGEE(vector<int> & arr){
    int n  = arr.size();
    vector<int>ans(n);
    stack<int>st;
    for(int i=0;i<n;i++){
        int curele = arr[i];
        while (!st.empty() && arr[st.top()] < curele)
        {
            st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return ans;
}
int main(){

    return 0;
}

/*   */