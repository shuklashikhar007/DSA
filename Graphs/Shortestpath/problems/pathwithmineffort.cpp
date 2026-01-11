#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int mineffort(vector<vector<int>> &hei){
    priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> pq;
    int n = hei.size();
    int m = hei[0].size();
    // Distance array jaha nahi pahuch sakte waha bahut badi vlaues store karege
    vector<vector<int>> dist(n, vector<int>(m,1e9));
    dist[0][0] = 0;
    pq.push({0, {0,0}});
    int dr[] = {-1,0,1,0};
    int dc[] = {0,1,0,-1};
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int diff = it.first;
        int r = it.second.first;
        int c = it.second.second;
        if(r == n- 1 && c == m- 1){
            // matlab destination pe pahuch gaye return the ans
            return diff;
        }
        for(int i=0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr >= 0 && nc >= 0 && nr < n && nc < m){
                int neffort = max(abs(hei[r][c] - hei[nr][nc]) , diff);
                if(neffort < dist[nr][nc]){
                    dist[nr][nc] = neffort;
                    pq.push({neffort , {nr , nc}});
                }
            }
        }
    }
    return 0;
    
    }
};
int main(){

    return 0;
}