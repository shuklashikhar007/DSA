#include<bits/stdc++.h>
using namespace std;
using teenkapair = pair<int , pair<int,int>>;
using dokapair = pair<int,int>;
class Solution{
    public:
    int cheap(int n, vector<vector<int>> &flights, int src , int dst , int k){
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : flights){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        priority_queue<dokapair, vector<dokapair> , greater<dokapair>> q;
        vector<int> dist(n, INT_MAX), ways(n,0);
        // Dist aur no of ways array bana lo
        dist[src] = 0; // src ki initial distance khud se is 0
        ways[src] = 1;// src tak pahuchne ka initially ek way hai khud se
        q.push({0,src});
        int mod = (int)(1e9+7);
        while (!q.empty())
        {
            int dis = q.top().first;
            int node = q.top().second;
            q.pop();
            for(auto it : adj[node]){
                int adjnode = it.first;
                int edw = it.second;
                if(dis + edw < dist[adjnode]){
                    dist[adjnode] = dis + edw;
                    // naya shortest distance mil gaya to update kardiya
                    q.push({dis+edw, adjnode});
                    // queue mai add for further processing
                    ways[adjnode] = ways[node];
                    // the number of ways to reach this node will be same as its parent node
                }
                // iska matlab hai jis parent node se ham is adjacent node par aye hai
                /// wo ek aur possible shortest rasta hai to reach this node 
                else if(dis + edw == dist[adjnode]){
                    // so now the number of ways to reach this node will be 
                    // jitne ways se pehle yaha a sakte the ways[adjnode] + ways to reach its parent node
                    ways[adjnode] = (ways[adjnode] + ways[node]) % mod;
                }
            }
        }
        return ways[dst] % mod;
    }
};
int main(){

    return 0;
}