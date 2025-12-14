// Cycle detection in Undirected graph using BFS
#include<bits/stdc++.h>
using namespace std;
class Solution{
    private :
    bool detect(int src, vector<int> adj[], int vis[]){
        vis[src] = 1;
        queue < pair < int , int >> q;
        q.push({src,-1});
        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            for(auto adjacent : adj[node]){
                if(!vis[adjacent]){
                    vis[adjacent] = 1;
                    q.push({adjacent,node});
                }
                // agar node visited hai lekin parent nahi hai that means there is a cycle present
                else if(parent != adjacent){
                    return true;
                }
            }
        }
        return false;
    }
    public :
    // This part we make sure to detect cycle in all components of the graph
    bool iscycle(int V, vector<int>adj[]){
        int vis[V] = {0};
        for(int i=0;i<V;i++){
            if(detect(i,adj,vis)) return true;
        }
        return false;
    }
};
int main(){
    vector<int>adj[4] = {{},{2},{1,3},{2}};
    Solution obj;
    return 0;
}