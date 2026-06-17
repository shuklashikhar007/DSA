#include<bits/stdc++.h>
using namespace std;
// learnt binary lifting to solve LC POTD 12/6/2026
const int LOG  = 20;
vector<vector<int>>adj;
vector<vector<int>> up;
vector<int>depth;
// kuch important defintions
/*
dfs(node, uska parent)
up[node][0] = immediate parent of node
up[node][j] = 2^jth ancestor of the node 
depth[node] = distance from root
*/
void dfs(int node, int parent){
    up[node][0] = parent;
    for(int j=1;j<LOG;j++){
        up[node][j] = up[up[node][j-1]][j-1];
    }
    for(int ch : adj[node]){
        if(ch == parent){ /// ye dikkat agar undirected tree hai to nahi ayegi 
            continue;
        }
        depth[ch] = depth[node] + 1;
        dfs(ch, node);
    }
}
// lifting a node k levels upar
// suppose diff = 13 hai 
// to we can lift like this => 8 + 4 + 1;
int lift(int node, int k){
    for(int j = LOG-1; j >= 0 ; j--){// LOG - 1 se isliye start kiya hai to move greedily 
        if(k & ( 1<< j)){ // agar jth bit on hai to go jsteps up 
            node = up[node][j];
        }
    }
    return node;
}
// LCA nikalne ka function
int lca(int u, int v){
    if(depth[u] < depth[v]){
        swap(u,v);
    }
    // jiski depth jyada hai obviosuly use hi lift karege 
    int diff = depth[u] - depth[v]; // bring u to the same depth as v
    for(int j = LOG-1 ; j >= 0; j--){
        if(diff & ( 1 << j)){
            u = up[u][j]; // 2^j steps upar le jao 
        }
    }
    if( u == v){
        // agar koi ek dusre ka ancestor tha to
        return u;
    }
    /*
    agar esa nahi hua to we will keep moving upward jab tak their 2^j ancetors are different
    */
   for(int j = LOG -1 ; j >=0 ; j--){ // yaha pe bhi start from LOG - 1 to maintain greedy 
    if(up[u][j] != up[v][j]){
         // differene becasue if they become equal to either ham jaha jane wale hai wo LCA hai ya to usse upar 
         // so to stay safe we only jump till its safe 
        u = up[u][j];
        v = up[v][j];
    }
   }
   return up[u][0]; // upar wala loop end hogaya matlab kisi ek ke just upar wala hi LCA hai 
}
int distbw(int u, int v){
    int L = lca(u,v);
    int ret = depth[u] + depth[v] - 2*depth[L];
    return ret;
}
int main(){
    int n;
    cin >> n;
    adj.resize(n+1);
    up.assign(n+1, vector<int>(LOG));
    depth.assign(n+1,0);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // pehli call 
    dfs(1,0);
    int q;
    cin >> q;
    while (q--)
    {
        int u,v;
        cin >> u >> v;
        cout << "LCA of u and v is : " << lca(u,v) << endl;
        cout << "Distance b/w them " << distbw(u,v) << endl;
    }
    return 0;
}