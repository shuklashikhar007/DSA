#include <bits/stdc++.h>
using namespace std;
void bfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis) {
    vis[i][j] = 1;
    queue<pair<int,int>> q;
    q.push({i, j});
    int n = grid.size();
    int m = grid[0].size();
    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        // Explore 8 directions
        for (int drow = -1; drow <= 1; drow++) {
            for (int dcol = -1; dcol <= 1; dcol++) {
                int r = row + drow;
                int c = col + dcol;
                if (r >= 0 && r < n && c >= 0 && c < m
                    && grid[r][c] == 1 && !vis[r][c]) {
                    vis[r][c] = 1;
                    q.push({r, c});
                }
            }
        }
    }
}
int dumaloo(vector<vector<int>>& grid, int n, int m) {
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && grid[i][j] == 1) {
                count++;
                bfs(i, j, grid, vis);
            }
        }
    }
    return count;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    int islands = dumaloo(grid, n, m);
    cout << islands << endl;
    return 0;
}
