#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long ans = 0;
    unordered_map<int,long long> freq;

    void dfs(int node,
             int mask,
             vector<vector<pair<int,int>>>& adj)
    {
        // Case 1: same mask
        ans += freq[mask];

        // Case 2: differ by one bit
        for(int bit = 0; bit < 26; bit++)
        {
            ans += freq[mask ^ (1 << bit)];
        }

        freq[mask]++;

        for(auto &[child, ch] : adj[node])
        {
            dfs(child, mask ^ (1 << ch), adj);
        }
    }

    long long countPalindromePaths(vector<int>& parent, string s) {

        int n = parent.size();

        vector<vector<pair<int,int>>> adj(n);

        for(int i = 1; i < n; i++)
        {
            adj[parent[i]].push_back(
                {i, s[i] - 'a'}
            );
        }

        freq[0] = 1; // empty/root prefix
        dfs(0, 0, adj);
        return ans;
    }
};
int main(){

    return 0;
}