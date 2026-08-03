#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<vector<int>>adj;
    vector<int>sz;
    vector<int>ans;
    void dfs1(int node, int parent, int depth){
        ans[0] += depth;
        sz[node] = 1;
        for(int child : adj[node]){
            if(child == parent) continue;
            dfs1(child,node,depth+1);
            sz[node] += sz[child];
        }
    }
    void dfs2(int node, int parent, int n){
        for(int ch : adj[node]){
            if(ch == parent) continue;
            ans[ch] = ans[node] + n - 2*sz[ch];
            dfs2(ch,node,n);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        adj.assign(n, {});
        sz.assign(n, 0);
        ans.assign(n, 0);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs1(0, -1, 0);
        dfs2(0, -1, n);     
        return ans;
    }
};

int main(){

    return 0;
}