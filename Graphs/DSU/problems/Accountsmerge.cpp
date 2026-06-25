// Understand this problem later
#include<bits/stdc++.h>
using namespace std;
class DSU{
public:
    vector<int> parent,size;
    DSU(int n){
        parent.resize(n);
        size.resize(n,1);
        iota(parent.begin(),parent.end(),0);
    }
    int find(int x){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    void unite(int u, int v){
        u = find(u);
        v = find(v);
        if(u == v) return; // already same component ka part hai
        if(size[u] < size[v]) swap(u,v);
        parent[v] = u;
        size[u] += size[v];
    }
};
class Solution{
    public:
    vector<vector<string>> accmerge(vector<vector<string>> &accounts){
        int n = accounts.size();
        DSU dsu(n);
        unordered_map<string,int>emailtoacc;
        for(int i=0;i<n;i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string email = accounts[i][j];
                if(emailtoacc.find(email) == emailtoacc.end()){ // matlabn this email has not been mapped to any other account earlier
                    emailtoacc[email] = i;
                }
                else{
                    dsu.unite(i, emailtoacc[email]); // agar pehle se kisi account se mapped hai to united cur and that account
                }
            }
        }
        unordered_map<int,set<string>> groups;
        for(auto &it : emailtoacc){
            string email = it.first;
            int acc = it.second;
            int parent = dsu.find(acc);
            groups[parent].insert(email);
        }
        vector<vector<string>>ans;
        for(auto &it : groups){
            int par = it.first;
            vector<string>cur;
            cur.push_back(accounts[par][0]);
            for(auto &email : it.second){
                cur.push_back(email);
            }
            ans.push_back(cur);
        }
        return ans;
    }
};
int main(){

    return 0;
}