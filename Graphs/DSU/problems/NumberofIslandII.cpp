// Do this problem later
#include<bits/stdc++.h>
using namespace std;
int main(){
    return 0;
}
class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findPar(int node) {
        if(parent[node] == node)
            return node;

        return parent[node] = findPar(parent[node]);
    }

    bool unite(int u, int v) {
        u = findPar(u);
        v = findPar(v);

        if(u == v) return false;

        if(size[u] < size[v])
            swap(u, v);

        parent[v] = u;
        size[u] += size[v];

        return true;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        DSU dsu(n * m);

        int islands = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // starting mai jitne 1 honge utne island honge present 
                if(grid[i][j] == '1')
                    islands++;
            }
        }

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == '0')
                    continue;

                int node = i * m + j;

                for(int k = 0; k < 4; k++) {

                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if(ni >= 0 && nj >= 0 &&
                       ni < n && nj < m &&
                       grid[ni][nj] == '1') {

                        int adjNode = ni * m + nj;

                        if(dsu.unite(node, adjNode))
                            islands--;
                    }
                }
            }
        }

        return islands;
    }
};