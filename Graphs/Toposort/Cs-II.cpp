#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<int> findorder(int nc, vector<vector<int>> & pre){
        vector<vector<int>> adj(nc);
        vector<int> indeg(nc,0);
        for(auto & p : pre){
            int a = p[0];
            int b = p[1];
            adj[b].push_back(a);
            indeg[a]++;
        }

        queue<int>q;
        for(int i=0;i<nc;i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }

        vector<int>order;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            order.push_back(node);

            // abb sare neigh ki indegree kam karo aur isi process mai kis ki indegree 0 ho jaye to queue mai 
            // push kardo usse bhi 
            for(int nei : adj[node]){
                indeg[nei]--;
                if(indeg[nei] == 0){
                    q.push(nei);
                }
            }
        }


        /// agar valid hai situation to return order else dont
        if(order.size() == nc){
            return order;
        }
        return {};
}
};
int main(){
    Solution sol;
    vector<vector<int>> pre = {{1,0}, {2,0} , {3,1} , {3,2}};
    int nc = 4;
    vector<int> ans = sol.findorder(nc,pre);
    for(int x : ans ) cout << x << " ";
    return 0;
}