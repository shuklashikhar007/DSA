#include<bits/stdc++.h>
using namespace std;
int main(){
    
}
class Solution {
  public:
    
    vector<string> ans;

    bool valid(int i, int j, int n, vector<vector<int>>& maze,
               vector<vector<int>>& vis) {

        if(i >= 0 && i < n &&
           j >= 0 && j < n &&
           maze[i][j] == 1 &&
           vis[i][j] == 0) {
            return true;
        }

        return false;
    }

    void solve(int i, int j, string &path, int n,
               vector<vector<int>> &maze,
               vector<vector<int>> &vis) {

        if(i == n-1 && j == n-1) {
            ans.push_back(path);
            return;
        }

        vis[i][j] = 1;

        // R
        if(valid(i, j+1, n, maze, vis)) {
            path += 'R';
            solve(i, j+1, path, n, maze, vis);
            path.pop_back();
        }

        // L
        if(valid(i, j-1, n, maze, vis)) {
            path += 'L';
            solve(i, j-1, path, n, maze, vis);
            path.pop_back();
        }

        // U
        if(valid(i-1, j, n, maze, vis)) {
            path += 'U';
            solve(i-1, j, path, n, maze, vis);
            path.pop_back();
        }

        // D
        if(valid(i+1, j, n, maze, vis)) {
            path += 'D';
            solve(i+1, j, path, n, maze, vis);
            path.pop_back();
        }

        vis[i][j] = 0;
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {

        int n = maze.size();

        if(maze[0][0] == 0 || maze[n-1][n-1] == 0) {
            return {};
        }

        vector<vector<int>> vis(n, vector<int>(n, 0));

        string path = "";

        solve(0, 0, path, n, maze, vis);

        return ans;
    }
};