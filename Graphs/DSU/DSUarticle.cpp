/*
Time Complexity: Nearly O(1) per operation with path compression and union by rank (technically O(α(n)) where α is the inverse Ackermann function)

Problems to Master
1. Number of Provinces
The perfect introduction to DSU! Given a graph of cities, find the number of connected components (provinces).

Key Insight: Each union operation merges two provinces. Count the number of distinct root nodes.

2. Accounts Merge
A fantastic problem that combines DSU with string processing!

Key Insight: Union accounts that share at least one email. Use a map to track email→account_id relationships.

3. Redundant Connection
Find the edge that creates a cycle in an undirected graph.

Key Insight: Process edges sequentially. The first edge where both nodes already belong to the same component creates a cycle!

4. Checking Existence of Edge Length Limited Paths
This is where DSU truly shines! Given queries asking if a path exists with all edges < limit, answer offline.

Key Insight:

Sort edges by weight and queries by limit
Process queries offline: build the graph incrementally using only edges below each query's limit
Use DSU to check connectivity at each query
5. Remove Max Number of Edges to Keep Graph Fully Traversable
One of my favorite DSU problems! Three types of edges: Alice-only, Bob-only, and shared.

Key Insight:

Greedy approach: prioritize shared edges (they help both)
Use two separate DSU structures for Alice and Bob
Count edges that don't contribute to connectivity
6. Similar String Groups
Strings are similar if they differ by exactly 2 positions. Group similar strings.

Key Insight: Treat each string as a node. Union similar strings. This demonstrates DSU's power with non-traditional "nodes"!

7. Smallest String With Swaps
You can swap characters at positions connected by given pairs. Find lexicographically smallest string.

Key Insight:

Positions that can be reached through swaps form components
Within each component, sort characters and positions independently
Assign sorted characters to sorted positions
8. Largest Component Size by Common Factor
Two numbers are connected if they share a common factor > 1. Find the largest component.

Key Insight:

Naive approach (check all pairs) is O(n²) - too slow!
Smart approach: union each number with its prime factors
Use factor→number mapping, not number→number
9. Satisfiability of Equality Equations
Given equations like "a==b" and "b!=c", determine if all can be satisfied.

Key Insight:

First pass: union all variables in "==" equations
Second pass: check all "!=" equations - return false if both variables in same component
10. Path With Minimum Effort
Find path from top-left to bottom-right minimizing maximum absolute difference.

Key Insight:

Binary search on effort OR
Sort all edges by effort, use DSU to find when start and end become connected (similar to Kruskal's MST!)

*/
#include<bits/stdc++.h>
using namespace std;
class DSU{
    public:
    vector<int>parent,size;
    DSU(int n){
        parent.resize(n);
        size.resize(n,1);
        iota(parent.begin(), parent.end(), 0);
    }
    int findparent(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findparent(parent[node]);
    }
    void unionbysize(int x, int v){
        int pu = findparent(x);
        int pv = findparent(v);
        if(pu == pv) return; // already same component mai hai 
        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        } 
        else{ // agar size[pu] >= size[pv]
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
int main(){
    


    return 0;
}