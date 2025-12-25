#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        // Function to find the shortest distance of all the vertices
        // from the source vertex S.
        vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
        {
            // Create a set ds for storing the nodes as a pair {dist,node}
            // where dist is the distance from source to the node.
            // set stores the nodes in ascending order of the distances.
            set<pair<int, int>> st; 

            // Initialising dist list with a large number to
            // indicate the nodes are unvisited initially.
            // This list contains distance from source to the nodes.
            vector<int> dist(V, 1e9); 

            // Insert the source node with a distance of 0.
            st.insert({0, S}); 

            // Source initialised with dist = 0
            dist[S] = 0;

            // Traverse the graph until the set is empty
            while(!st.empty()) {
                // Extract the node with the minimum distance
                auto it = *(st.begin()); 
                int node = it.second; 
                int dis = it.first; 
                st.erase(it); 

                // Check for all adjacent nodes of the extracted node
                for(auto it : adj[node]) {
                    int adjNode = it[0];  // Adjacent node
                    int edgW = it[1];     // Weight of the edge
                    
                    // If the new distance is smaller, update it
                    if(dis + edgW < dist[adjNode]) {
                        // Erase the previous entry of the adjacent node
                        // if it was visited previously with a larger cost.
                        if(dist[adjNode] != 1e9) 
                            st.erase({dist[adjNode], adjNode}); 

                        // Update the distance for the adjacent node
                        dist[adjNode] = dis + edgW; 

                        // Insert the adjacent node with the updated distance into the set
                        st.insert({dist[adjNode], adjNode}); 
                    }
                }
            }

            // Return the list containing shortest distances
            // from source to all the nodes.
            return dist; 
        }
};

int main()
{
    // Driver code.
    int V = 3, E = 3, S = 2;  // Number of vertices, edges, and source vertex
    vector<vector<int>> adj[V]; // Adjacency list representation of the graph

    // Example graph with edges and weights
    vector<int> v1{1, 1}, v2{2, 6}, v3{2, 3}, v4{0, 1}, v5{1, 3}, v6{0, 6};
    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[2].push_back(v5);
    adj[2].push_back(v6);

    Solution obj;
    // Call dijkstra function and store the result
    vector<int> res = obj.dijkstra(V, adj, S);

    // Output the shortest distance from source to all nodes
    for (int i = 0; i < V; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
