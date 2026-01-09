#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    using ll = long long;

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        ll n = grid.size();
        if(n == 0) return -1;

        // agar start ya end blocked hai to impossible
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        // pehle wo point jaha hame pahuchna hai
        ll destx = n-1, desty = n-1;

        // ye wo point jaha se chalna shuru karna hai hame
        ll srcx = 0, srcy = 0;

        // queue mai data is form mai hai -> ({distfromsrc , {row,col}})
        queue<pair<ll, pair<ll,ll>>> q;

        vector<vector<ll>> dist(n, vector<ll>(n, 1e9));

        // BFS start point ka distance 1 hota hai
        dist[srcx][srcy] = 1;
        q.push({1, {srcx, srcy}});

        // 8 directions
        ll dr[] = {-1,-1,-1,0,0,1,1,1};
        ll dc[] = {-1,0,1,-1,1,-1,0,1};

        while(!q.empty()){
            auto point = q.front();   // pair<ll, pair<ll,ll>>
            q.pop();

            ll dis = point.first;
            ll r = point.second.first;
            ll c = point.second.second;

            // agar destination mil gaya
            if(r == destx && c == desty) return dis;

            // abb sari 8 directions check
            for(int i = 0; i < 8; i++){
                ll nr = r + dr[i];
                ll nc = c + dc[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < n &&
                   grid[nr][nc] == 0 && dis + 1 < dist[nr][nc]){

                    /// iska matlab naya shortest path milgaya
                    dist[nr][nc] = dis + 1;   // store naya distance
                    q.push({dis + 1, {nr, nc}});
                }
            }
        }
        return -1; // agar destination kabhi reach hi nahi hua
    }
};
int main(){
    return 0;
}

