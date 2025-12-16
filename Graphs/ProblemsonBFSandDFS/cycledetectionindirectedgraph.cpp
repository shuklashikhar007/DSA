// Detect Cycle in a directed graph using DFS
#include<bits/stdc++.h>
using namespace std;
bool dfs(int node, vector<int>adj[], int vis[], int pathvis[]){
    vis[node] = 1;
    pathvis[node] = 1;
    // traverse for adjacent nodes
    for(auto it : adj[node]){
        if(!vis[it]){ // if not visited
            if(dfs(it,adj,vis,pathvis) == true){
                return true;
            }
            else{ // if visited and also path visited -> cycle
                return true;
            }
        }
    }
 // when returning (nocycle ya adj node wala case ) remove elements from the path vis array as well

    pathvis[node] = 0;
    return false;
}
int main(){
    /*
    // calling code so that all components are covered
    V- no of nodes
    int vis[V] = {0};
    int pathvis[V] = {0};
     for(int i=0;i<V;i++){
        if(!vis[i]){ // if not visited
           if(dfs(i,adj,vis,pathvis) == true){
            return true;
           } 
        }
     }
    return false; -> sare components check no cycle found
    */
    return 0;
}