#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int netdelay(vector<vector<int>> & times, int n, int k){
        // pehle adj list bana lo
        vector<vector<pair<int,int>>> adj(n+1);
        // yaha par adj node ke sath sath weight bhi store karna hai that's why 
        // hamne vector pair data type liya hai
        for(auto & time : times){
            int u = time[0], v = time[1], w = time[2];
            adj[u].push_back({v,w});
        }
        // min heap bana liya
        // to always process the shortest distance first
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        //  {dist, node}
        pq.push({0,k});
        vector<int> dist(n+1, INT_MAX);
        // ye nahi bhulna hai to initialize the distance of src node with 0
        dist[k] = 0;
        while (!pq.empty())
        {
            int t = pq.top().first;
            // source node se iss node ka distance
            int node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                int w = it.second;
                int nbr = it.first;
                if(t + w< dist[nbr]){
                    dist[nbr] = t + w;
                    pq.push({t+w , nbr});
                }
            }
        }
        // max element isliye because atleast itna time to lag hi jayega
        int ans = *max_element(dist.begin()+1, dist.end());
        return ans == INT_MAX ? -1 : ans;
    }
};
int main(){

    return 0;
}