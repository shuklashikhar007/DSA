// to generate all perm of an arr if it contains duplicate numbers
#include<bits/stdc++.h>
using namespace std;
void permute(int ind, vector<int>&a,int n){
    if(ind == n){
        for(int x: a) cout << x << " ";
        cout << endl;
        return;
    }
    unordered_set<int>usedhai;
    for(int i=ind;i<n;i++){
        if(usedhai.count(a[i])) continue; 
        usedhai.insert(a[i]); // ek bar use kiya to dubara nahi karna hai
        // agar pehle used hai to skip this iteration straight away
        swap(a[ind],a[i]);
        permute(ind+1,a,n);
       // swap(a[ind],a[i]);
    }
}
int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    permute(0,a,n);
    return 0;
}