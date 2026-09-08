#include<bits/stdc++.h>
using namespace std;
// Next Smaller Element (right side) — strict, sentinel = n
vector<int> findNSE(vector<int>& arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;
    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        ans[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return ans;
}
// Next Greater Element (right side) — strict, sentinel = n
vector<int> findNGE(vector<int>& arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;
    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && arr[st.top()] <= arr[i]){
            st.pop();
        }
        ans[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return ans;
}
// Previous Smaller-or-Equal Element (left side) — sentinel = -1
vector<int> findPSEE(vector<int>& arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return ans;
}
// Previous Greater-or-Equal Element (left side) — sentinel = -1
vector<int> findPGEE(vector<int>& arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && arr[st.top()] < arr[i]){
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