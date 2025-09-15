#include<bits/stdc++.h>
using namespace std;
int main(){
    map < string , array<int,3>> mpp;
    mpp["alice"] = {1,2,3};
    mpp["bob"] = {4,5,6};
    for(auto &p : mpp){ // iterator in a map
        cout << p.first << "->";
        for(int x : p.second){
            cout << x << " " ;
        }
        cout << endl;
    }
    return 0;
}