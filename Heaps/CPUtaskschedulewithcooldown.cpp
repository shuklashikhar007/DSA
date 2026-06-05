#include<bits/stdc++.h>
using namespace std;
int main(){
    
}
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time = 0;
        map<char,int>mpp;
        // pq batayega ki max freq wala task konsa left hai abhi 
        // queue will tell the latest task jiska cooldown hone wala hai 
        for(char c : tasks) mpp[c]++;
        priority_queue<int>pq;
        for(auto it : mpp){
            pq.push(it.second);
        }
        queue<pair<int,int>>q; // ye store karega {{freq, cooldowntime}}
        while(!pq.empty() || !q.empty()){ // jabtak dono khali nahi ho jate tab tak chaleyeg
            time++;
            if(!pq.empty()){
                int f = pq.top();
                pq.pop();
                f--;
                if(f>0){
                    q.push({f,time+n});
                }
            }
            if(!q.empty() && q.front().second == time){ // natlab jo sabse first gya tha is now avail for execution
                // to isko wapis pq mai dal do
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
