#include<bits/stdc++.h>
using namespace std;
int main(){
    class Solution{
        public :
        int findpro(vector<vector<int>> &adj){
            int n = adj.size();
            int pro = 0;
            vector<int>vis(n,0);
            for(int i=0;i<n;i++){
                if(!vis[i]){
                    pro++;
                    queue<int>q;
                    q.push(i);
                    vis[i] = 1;

                    while (!q.empty())
                    {
                        int node = q.front();
                        q.pop();
                        for(int j = 0; j < n;j++){
                            if(adj[node][j] == 1 && !vis[j]){
                                vis[j] = 1;
                                q.push(j);
                            }
                        }
                    }
                    
                }
            }
            return pro;
        }
    };
}