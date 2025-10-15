#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>height = {30,10,60,10,60,50};
    int n = height.size();
    int prev = 0;
    int prev2 = 0;
    for(int i=1;i<n;i++){
        int jumptwo = INT_MAX;
        int jumpone = prev + abs(height[i] - height[i-1]);
        if(i>1){
            jumptwo = prev2 + abs(height[i]- height[i-2]);
        }
        int cur = min(jumpone,jumptwo);
        prev2 = prev;
        prev = cur;
    }
    cout << prev;
    return 0;
}