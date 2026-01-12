// Thoda sa ajeeb sa question infact cannot be done agar pehle se concept nahi pata to
#include<bits/stdc++.h>
using namespace std;
class DSU {
public:
    unordered_map<int, int> parent;
    // Function to find the ultimate parent of node x
    int find(int x) {
        // If x is not present, make it its own parent
        if (parent.find(x) == parent.end())
            parent[x] = x;

        // Path compression to optimize future finds
        if (x != parent[x])
            parent[x] = find(parent[x]);

        return parent[x];
    }
    // Function to connect two nodes
    void unite(int x, int y) {
        // Set parent of x's root to y's root
        parent[find(x)] = find(y);
    }
};
class Solution{
    public:
    int remove(vector<vector<int>> &stones){
        DSU dsu;
        for(auto & stone : stones){
            dsu.unite(stone[0] , stone[1] + 10001);
        }
        // count unique components ? -> what does this evene mean
        unordered_set<int>components;
        for(auto & stone : stones){
            components.insert(dsu.find(stone[0]));
        }
        return stones.size() - components.size();
    }
};
int main(){

    return 0;
}