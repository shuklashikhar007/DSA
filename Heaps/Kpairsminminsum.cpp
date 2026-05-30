#include<bits/stdc++.h>
using namespace std;
int main(){
    
    return 0;
}
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // bahut accha PQ ka question 
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        int n = nums1.size(), m = nums2.size();
        set<pair<int,int>>vis; // kon kon se pair of index pe visit ho gaya ho uska hisab rakhne ke liye visited set
        pq.push({nums1[0] + nums2[0], {0,0}}); // push pehle pairs ka sum as this will be minimum 
        vis.insert({0,0});
        vector<vector<int>>ans;
        while(k-- && !pq.empty()){
            auto it = pq.top();
            pq.pop();
            int i = it.second.first;
            int j = it.second.second;
            ans.push_back({nums1[i],nums2[j]});
            if(i+1 < n  && !vis.count({i+1,j})){
                pq.push({nums1[i+1] + nums2[j], {i+1,j}});
                vis.insert({i+1,j});
            }
            if(j+1 < m && !vis.count({i,j+1})){
                pq.push({nums1[i] + nums2[j+1], {i,j+1}});
                vis.insert({i,j+1});
            }
        }
        return ans;
    }
};