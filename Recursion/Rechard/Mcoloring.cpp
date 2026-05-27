#include <iostream>
#include <vector>
using namespace std;
#define V 4 // Number of vertices
// Check if neighbors have the same color
bool isSafe(int v, const vector<vector<int>>& graph, const vector<int>& color, int c) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i]) return false;
    return true;
}
// Recursive Backtracking Function
bool solveColoring(const vector<vector<int>>& graph, int m, vector<int>& color, int v) {
    if (v == V) return true; // Base case: All vertices colored
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c; // Assign color
            if (solveColoring(graph, m, color, v + 1)) return true;
            color[v] = 0; // Backtrack
        }
    }
    return false;
}
int main() {
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    int m = 3; 
    vector<int> color(V, 0);

    if (solveColoring(graph, m, color, 0)) {
        cout << "Graph can be colored!";
    } else {
        cout << "Solution does not exist.";
    }
    return 0;
}