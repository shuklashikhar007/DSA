// Way - 1 to represent a Graph in C++
// 1st way is by making a ((n+1)x(n+1)) matrix where n is the no of nodes
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m; // here n is the no of nodes
    cin >> n >> m; // here m is the no of edges
    vector<vector<int>> arr(n+1, vector<int>(n+1,0));
    for(int i=0;i<m;i++){ // loop will run the no of times equal to the number of edges
        // because each edge connects two nodes
        int u,v;
        cin >> u >> v;
        arr[u][v] = 1;
        arr[v][u] = 1;
    }
    cout << "The graph is stored as follows -> " << endl;
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}