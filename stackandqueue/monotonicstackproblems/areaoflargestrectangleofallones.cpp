#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int n = matrix.size(), m = matrix[0].size();
        vector<int> heights(m, 0);
        int maxArea = 0;

        for (int i = 0; i < n; i++) {

            // Step 1: Build histogram
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') heights[j] += 1;
                else heights[j] = 0;
            }

            // Step 2: Apply NSL + NSR histogram logic
            maxArea = max(maxArea, largestRectangleAreaNS(heights));
        }

        return maxArea;
    }

private:
    int largestRectangleAreaNS(vector<int>& heights) {
        int n = heights.size();
        vector<int> NSL(n), NSR(n);
        stack<int> st;

        // NSL
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            NSL[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        // clear stack
        while (!st.empty()) st.pop();
        // NSR
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            NSR[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        // Compute max area
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = NSR[i] - NSL[i] - 1;
            maxArea = max(maxArea, heights[i] * width);
        }
        return maxArea;
    }
};