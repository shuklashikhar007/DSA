#include<bits/stdc++.h>
using namespace std;
class Solution{
    public :
    bool can(int nc , vector<vector<int>> & pre){
        // sabse pehle adj list bana lenge
        vector<vector<int>> adj(nc);
        // degree array -> ek node pe kitne incoming edges hai wo us node ki degree hoti hai
        vector<int> isdeg(nc,0);
        for(auto & p : pre ){
            int a = p[0];
            int b = p[1];
            // yaha pe a pushed in list of b because in question graph edge is from b -> a not the reverse
            // since ye ek directed graph hai node b ->>a hai to edges goes from b to a
            adj[b].push_back(a);
            isdeg[a]++;
        }
        // queue ke andar intitally wo nodes jinki indegree zero hai
        queue<int>q;
        for(int i=0;i<nc;i++){
            if(isdeg[i] == 0){
                q.push(i);
            }
        }
        int count = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;
            for(int nei : adj[node]){
                isdeg[nei]--;
                if(isdeg[nei] == 0){
                    q.push(nei);
                }
            }
        }
        return count == nc;
    }
};
int main(){
    Solution sol;
    // ek class jisme functions hai uska instance create karna 
    // main code body ke andar
    vector<vector<int>> pre = {{1,0} , {0,1}};
    int ncour = 2;
    cout << (sol.can(ncour,pre) ? "true" : "false");
    return 0;
}