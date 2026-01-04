#include<bits/stdc++.h>
using namespace std;
class Solution{
    public :
        vector<int> event(vector<vector<int>> &graph){
            int n = graph.size();
            // pehle graph ko reverse kardiya
            vector<vector<int>> rev(n);
            // har node ki outdegree
            vector<int>outdeg(n,0);
            for(int u=0;u<n;u++){
                // us parti node u se kitne edges bahar ja rahe hai
                outdeg[u] = graph[u].size();
                for(int v : graph[u]){
                    rev[v].push_back(u);
                    // reverse all the edges and store it
                }
            }
            // queue ke andar terminal nodes dal do
            queue<int>q;
            // outdeg 0 matlab no nodes go out of this node
            for(int i=0;i<n;i++){
                if(outdeg[i] == 0){
                    q.push(i);
                }
            }
            // safe nodes ko mark karne ke liye
            vector<bool> safe(n,false);
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                safe[node] = true;
                // parent node ki outdegree kam kar denge
                for(int parent : rev[node]){
                    outdeg[parent]--;
                    if(outdeg[parent] == 0){
                        q.push(parent);
                    }
                }
            }
            // step - 5 collect safe nodes
            vector<int>ans;
            for(int i=0;i<n;i++){
                if(safe[i]) ans.push_back(i);
            }            
            return ans;
        }
};
int main(){

    return 0;
}