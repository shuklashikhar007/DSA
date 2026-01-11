/*
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cheap(int n, vector<vector<int>>& flight, int src, int dest, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &it : flight){
            adj[it[0]].push_back({it[1], it[2]});
        }

        // dist[node][stops_left]
        vector<vector<int>> dist(n, vector<int>(k+2, 1e9));

        // min-heap: (cost, node, stops_left)
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<>
        > pq;

        pq.push({0, src, k+1});   // k+1 edges allowed
        dist[src][k+1] = 0;

        while(!pq.empty()){
            auto [cost, node, stops] = pq.top();
            pq.pop();

            if(node == dest) return cost;   // cheapest found

            if(stops == 0) continue;        // no more flights allowed

            for(auto [next, w] : adj[node]){
                if(cost + w < dist[next][stops-1]){
                    dist[next][stops-1] = cost + w;
                    pq.push({cost + w, next, stops - 1});
                }
            }
        }
        return -1;
    }
};





*/