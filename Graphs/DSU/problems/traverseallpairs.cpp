#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    class DSU{
        public:
        vector<int>size,par;
        int comp;
        DSU(int n){
            size.resize(n,1);
            par.resize(n);
            iota(par.begin(),par.end(),0); // fill all the parents 
            comp = n;
        }
        int findpar(int node){
            if(node == par[node]) return node;
            return par[node] = findpar(par[node]);
        }
        void unbysize(int u, int v){
            int pu = findpar(u);
            int pv = findpar(v);
            if(pu == pv) return;
            if(size[pu] < size[pv]){
                par[pu] = pv;
                size[pv] += size[pu];
            }
            else{
                par[pv] = pu;
                size[pu] += size[pv];
            }
            comp--;
        }

    };
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        DSU dsu(n);
        int maxi = *max_element(nums.begin(),nums.end());
        vector<vector<int>>adj(maxi+1);
        for(int i=0;i<n;i++){
            int num = nums[i];
            for(int p = 2 ; p*p <= num; p++){
                if(num%p != 0) continue;
                adj[p].push_back(i);
                while(num%p == 0) num /= p; // remove sari powers p ki 
                // upar wala step only when we need prime factors not all factors
            }
            if(num > 1){ // iska matlab ye wo wlaa factor hai that was greater than root n
                adj[num].push_back(i);
            }
        }
        int m = adj.size();
        for(int i = 0 ; i < m ; i++){
            if(!adj[i].empty()){
                for(int j=0; j<adj[i].size()-1; j++){
                    dsu.unbysize(adj[i][j], adj[i][j+1]);
                }
            }
        }
        int com = dsu.comp;
        if(com == 1) return true;
        else return false;
    }
};
int main(){
    Solution sol;
    
    return 0;
}