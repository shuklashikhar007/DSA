#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        priority_queue<pair<int, pair<int,int>>,vector<pair<int, pair<int,int>>>,greater<pair<int, pair<int,int>>>>pq;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        pq.push({matrix[0][0], {0, 0}});
        vis[0][0] = true;
        int sz = k-1;
        while (sz--) {
            auto cur = pq.top();
            pq.pop();
            int x = cur.second.first;
            int y = cur.second.second;
            if (x + 1 < n && !vis[x + 1][y]) {
                pq.push({matrix[x + 1][y], {x + 1, y}});
                vis[x + 1][y] = true;
            }
            if (y + 1 < m && !vis[x][y + 1]) {
                pq.push({matrix[x][y + 1], {x, y + 1}});
                vis[x][y + 1] = true;
            }
        }
        return pq.top().first;
    }
};
int main(){
    return 0;
}