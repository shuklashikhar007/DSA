#include<bits/stdc++.h>
using namespace std;
void print(vector<int>&a){
    for(int i=0;i<a.size();i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
void permute(int ind, vector<int>&a, int n){
    if(ind == n){
        print(a);
        return ;
    }
    for(int i=ind;i<n;i++){
        swap(a[ind],a[i]);
        permute(ind+1,a,n);
      //  swap(a[ind],a[i]);
    }
}
int main(){
    vector<int>a = {1,2,3};
    permute(0,a,3);
    return 0;
}