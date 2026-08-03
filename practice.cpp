#include<bits/stdc++.h>
using namespace std;
vector<int>findval(vector<int>&mem){
    int n = mem.size();
    vector<int>freq(n+1,0);
    for(int x : mem){
        freq[x]++;
    }
    set<int>mis;
    for(int i=0;i<=n;i++){
        if(freq[i] == 0){
            mis.insert(i);
        }
    }
    set<int>ans;
    ans.insert(*mis.begin());
    for(int i=0;i<n;i++){
        int x = mem[i];
        if(x == n-1)continue; // isko badha nahi sakte hai iska matlab
        // x ko hatao
        freq[x]--;
        if(freq[x] == 0){
            mis.insert(x);
        }
        // add karo x + 1 ko 
        freq[x+1]++;
        if(freq[x+1] == 1){
            mis.erase(x+1);
        }
        ans.insert(*mis.begin());
        // wapis layo is number ko 
        freq[x+1]--;
        if(freq[x+1] == 0){
            mis.insert(x+1);
        }
        freq[x]++;
        if(freq[x] == 1){
            mis.erase(x);
        }
    }
    return vector<int>(ans.begin(),ans.end());
}
int main(){

}