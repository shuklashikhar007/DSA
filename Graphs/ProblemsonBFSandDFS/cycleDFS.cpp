// cycle detection in undirected graph using DFS
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    bool dfs(int node, int parent, vector<int>adj[], vector <int>& visited){
        visited[node] = 1; // pehle mark the current node visited then travers all it's neighbours
        for(int neigh : adj[node]){
            if(!visited[neigh]){
                if(dfs(neigh,node,adj,visited)) return true;
            }
            // if neighbour visited but not parent -> cycle hai yaha pe
            else if(neigh != parent){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]){
        vector<int>visited(V,0); // visited array
        // check all the components for a cycle

        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i,-1,adj,visited)) return true; // very intresting line 
            }
        }
        return false;
    }
};
int main(){
    // Example: Graph with 5 nodes and a cycle
    int V = 5;
    vector<int> adj[V];

    // Add edges
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(3);
    adj[4].push_back(1); 

    Solution sol;
    if (sol.isCycle(V, adj))
        cout << "Cycle detected\n";
    else
        cout << "No cycle found\n";

    return 0;
    return 0;
}