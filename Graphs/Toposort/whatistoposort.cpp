// To find Topo sort using DFS
#include<bits/stdc++.h>
using namespace std;
void dfs(int node, int vis[] , stack<int>st,vector<int>adj[]){
    // sabse pehle jis node ke liye function call uske visited mark karege
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it, vis,st,adj);
        }
    }
    st.push(node);
}
vector<int> toposort(int V, vector<int>adj[]){
    int vis[V] = {0}; // vis array 
    stack<int>st;
    for(int i=0;i<V;i++){
        if(!vis[i]){ // agar visited nahi hai node to 
            dfs(i,vis,st,adj);
        }
    }
    vector<int>ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
int main(){
    // if there is a node b/w u and v then in topo sort u should come before v

    return 0;
}