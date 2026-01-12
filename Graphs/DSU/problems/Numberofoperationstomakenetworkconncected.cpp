#include<bits/stdc++.h>
using namespace std;
class DSU{
    public:
    vector<int>parent, rank;
    // DSU ko initialize kar lenge with n nodes
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n,0);
        // call ke according parent aur rank ka size bana lo
        // Starting mai har node khud ka hi parent hota hai
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    // Union by rank
    void unite(int x ,int y){
        int px = find(x);
        int py = find(y);
        // agar do nodes ka ultimate parent same hai to
        if(px == py) return;
        if(rank[px] < rank[py]){
            // ye ke ulitmate parent ka tree bada hai x ke ulitmate parent ke tree se 
            // so we will connect x's tree below y
            parent[px] = py;
        }
        // upar wale case ka opposite
        else if(rank[px] > rank[py]){
            parent[py] = px;
        }
        else{
            // equal wala case mai increase the rank below which
            // the other is connceted
            parent[py] = px;
            rank[px]++;
        }
    }
};
class Solution{
    public:
    int make(int n, vector<vector<int>> & connect){
        // agar no of edges n-1 se kaam hai we cannot connect at all
        if(connect.size() < n-1) return -1;
        DSU dsu(n);
        // connect components
        for(auto & edge : connect){
            dsu.unite(edge[0], edge[1]);
        }
        // no of unique components count karlo
        unordered_set<int> components;
        for(int i=0;i<n;i++){
            components.insert(dsu.find(i));
        }
        return components.size() - 1;
    }
};
int main(){

    return 0;
}