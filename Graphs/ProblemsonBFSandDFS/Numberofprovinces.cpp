// First Method by applying DFS on adj matrix
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void dfs(int node, vector<vector<int>>&adls, vector<int>&vis){
        vis[node] = 1;
        for(int j=0;j<adls.size();j++){
            if(adls[node][j] == 1 && !vis[j]){
                dfs(j,adls,vis);
            }
        }
    }
    int findp(vector<vector<int>> &adj){
    int n = adj.size();
    vector<int>vis(n,0);
    int pro = 0;

    for(int i=0;i<n;i++){
        if(!vis[i]){
            pro++;
        }
        dfs(i,adj,vis);
    }
    return pro;
}
};
int main(){
    return 0;
}