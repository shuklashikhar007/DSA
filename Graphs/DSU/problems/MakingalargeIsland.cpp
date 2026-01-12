#include<bits/stdc++.h>
using namespace std;
class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++) parent[i] = i;
    }
    int findUPar(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v){
        int pu = findUPar(u);
        int pv = findUPar(v);
        if(pu == pv) return;

        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
class Solution {
public:
    vector<int> delrow = {-1,0,1,0};
    vector<int> delcol = {0,1,0,-1};
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        // Step 1: Connect all existing 1s
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c] == 0) continue;
                for(int k=0;k<4;k++){
                    int nr = r + delrow[k];
                    int nc = c + delcol[k];
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                        int node1 = r*n + c;
                        int node2 = nr*n + nc;
                        ds.unionBySize(node1, node2);
                    }
                }
            }
        }
        int ans = 0;
        // Step 2: Try flipping each 0
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c] == 1) continue;
                unordered_set<int> components;
                for(int k=0;k<4;k++){
                    int nr = r + delrow[k];
                    int nc = c + delcol[k];
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                        // jo nei mai 1 mila uske component mai join hoke size nikalne ka try karenge
                        int node = nr*n + nc;
                        components.insert(ds.findUPar(node));
                    }
                }
                int total = 1;  // flipped cell
                for(auto root : components){
                    total += ds.size[root];
                }
                ans = max(ans, total);
            }
        }
        // Step 3: If grid already full of 1s
        for(int i=0;i<n*n;i++){
            ans = max(ans, ds.size[ds.findUPar(i)]);
        }
        return ans;
    }
};
int main(){

    return 0;
}