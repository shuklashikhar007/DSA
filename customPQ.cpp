#include<bits/stdc++.h>
using namespace std;
int main(){
    
}
class EventManager {
public:
    struct Compare{
        bool operator()(pair<int,int>a, pair<int,int>b){
            if(a.first != b.first){
                return a.first < b.first;
            }
            return a.second > b.second;
        }
    };
    priority_queue<pair<int,int>, vector<pair<int,int>> , Compare> pq;
    map<int,int>mp;
    EventManager(vector<vector<int>>& events) {
        for(auto &e : events){
            int id = e[0];
            int pri = e[1];
            mp[id] = pri;
            pq.push({pri,id});
        }
    }
    void updatePriority(int eventId, int newPriority) {
        mp[eventId] = newPriority;
        pq.push({newPriority, eventId});   
    }
    int pollHighest() {
        while(!pq.empty()){
            auto top = pq.top();
            int pri = top.first;
            int id = top.second;
            // event already removed hai
            if(mp.find(id) == mp.end()){
                pq.pop();
            }
            // pri outdated hai matlab ye stale value hai remove this
            else if(mp[id] != pri){
                pq.pop();
            }
            else{ // mil gayi valid entry
                break;
            }
        }
        if(pq.empty()) return -1;
        int ans = pq.top().second; // event ki id hai ye wali
        pq.pop();
        mp.erase(ans);
        return ans;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */