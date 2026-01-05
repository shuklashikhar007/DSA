#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    // src and dest cell bhi pass kardenge
    int shortest(vector<vector<int>> &grid, pair<int, int> src, pair<int,int> dest ){
        if(src.first == dest.first && src.second == dest.second){
            return 0;
        }
        // BFS ke liye queue jisme cells aur unka dist source se store hoga
        queue<pair<int,pair<int,int>>>q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m,1e9));
        dist[src.first][src.second] = 0;
        // src ka khud se distance 0 hai
        q.push({0, {src.first , src.second}});
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            // sare 4 directions mai check karenge
            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if( nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc]== 1 && dis + 1 < dist[nr][nc] && grid[nr][nc] == 1){
                    // matlab naya shortest distance milgaya
                    dist[nr][nc] = 1 + dis;
                    // update it 
                    if(nr == dest.first && nc == dest.second){
                        // matlab we reached our destination
                        return dis + 1;
                    }
                    // else push this into queue for future process
                    q.push({1+dis  , {nr,nc} });

                }
            }
        }
        return -1;

    }
};
int main(){
    // jaha se chalna start kiya
    pair<int, int> src= {0,0};
    // jaha pahuchna hai
    pair<int,int> dest = {2,2};
     vector<vector<int>> grid = {{1, 1, 1, 1},
                                 {1, 1, 0, 1},
                                 {1, 1, 1, 1},
                                 {1, 1, 0, 0},
                                 {1, 0, 0, 1}};
    Solution obj;
    int res = obj.shortest(grid, src, dest);
    // Output the result
    cout << res << endl;

    return 0;
}