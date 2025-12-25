#include<bits/stdc++.h>
using namespace std;
int findpar(int u, vector<int>&par){
    if(u == par[u]){
        return u;
    }
    return par[u] = findpar(par[u], par);
}
int main(){

    return 0;
}