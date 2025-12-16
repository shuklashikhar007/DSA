#include<bits/stdc++.h>
using namespace std;

void dfs(int row, int col,
         vector<vector<int>> &vis,
         vector<vector<char>> &grid,
         vector<pair<int,int>> &v,
         int row0, int col0)
{
    vis[row][col] = 1;
    v.push_back({row - row0, col - col0});

    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    int n = grid.size();
    int m = grid[0].size();

    for(int i = 0; i < 4; i++){
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if(nrow >= 0 && nrow < n &&
           ncol >= 0 && ncol < m &&
           !vis[nrow][ncol] &&
           grid[nrow][ncol] == '1')
        {
            dfs(nrow, ncol, vis, grid, v, row0, col0);
        }
    }
}

int disisland(vector<vector<char>> grid){
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));
    set<vector<pair<int,int>>> st;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j] && grid[i][j] == '1'){
                vector<pair<int,int>> v;
                dfs(i, j, vis, grid, v, i, j);
                st.insert(v);
            }
        }
    }
    return st.size();
}

int main(){
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    cout << disisland(grid) << endl;
    return 0;
}
