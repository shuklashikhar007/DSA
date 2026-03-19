#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> NSL(n), NSR(n);
        stack<int> st;

        // NSL
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            NSL[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // clear stack
        while(!st.empty()) st.pop();

        // NSR
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            NSR[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        long long maxArea = 0;
        for(int i = 0; i < n; i++){
            int width = NSR[i] - NSL[i] - 1;
            maxArea = max(maxArea, (long long)heights[i] * width);
        }
        return (int)maxArea;
    }
};