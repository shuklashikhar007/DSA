#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static bool comp(vector<int>&a, vector<int>&b){
        int afir = a[0], asec = a[1];
        int bfir = b[0], bsec = b[1];
        if(afir != bfir){
            return (afir < bfir);
        }
        else return asec > bsec;
    }
    int removeCoveredIntervals(vector<vector<int>>& inter) {
        int n = inter.size();
        sort(inter.begin(),inter.end(), comp);
        vector<vector<int>>ans;
        ans.push_back(inter[0]);
        for(int i=1;i<n;i++){
            if(inter[i][0] >= ans.back()[0] && inter[i][1] <= ans.back()[1]){
                // iska matlab current interval is completely covered here 
                continue;
            }
            else{
                ans.push_back(inter[i]);
            }
        }
        int ret = ans.size();
        return ret;
    }
};
int main(){

    return 0;
}