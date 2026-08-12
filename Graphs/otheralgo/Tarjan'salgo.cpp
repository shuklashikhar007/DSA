#include<bits/stdc++.h>
using namespace std;
class Tarjan{
    public:
    int n, timer;
    vector<vector<int>> adj;
    vector<int> tin,low;
    vector<bool> vis,isart;
    vector<pair<int,int>> bridges;
    Tarjan(int nodes){
        n = nodes;
        adj.resize(n);
        tin.resize(n,-1);
        low.assign(n,-1);
        vis.assign(n,false);
        isart.assign(n,false);
        timer = 0;
    }
    void addedge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void dfs(int node, int par= -1){
        vis[node] = true;
        tin[node] = low[node] = timer++; 
        int ch = 0;
        for(int it : adj[node]){
            if(it == par) continue;
            if(!vis[it]){
                dfs(it,node);
                low[node] = min(low[node],low[it]);
                if(low[it] > tin[node]){
                    bridges.push_back({node,it});
                }
                // art point ki condtion 
                if(par != -1 && low[it] >= tin[node]){
                    isart[true]; // matlab sare points on a bridge are art points
                }
                ch++;
            }
            else{ // nei node parent nahi hai aur already visited hai 
                // this means ye ek back edge hai yaha par
                low[node] = min(low[node], tin[it]); 
            }
        }
        if(par == -1 && ch > 1){
            isart[node] = true;
        } 
    }
    void build(){
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i);
            }
        }
    }
    vector<pair<int,int>> getbri(){
        return bridges;
    }
    vector<int>getartpoints(){
        vector<int>ans;
        for(int i=0 ; i < n;i++){
            if(isart[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
int main(){
    
    return 0;
}