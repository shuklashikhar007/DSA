/// Recursive method to print all possible subsequences of an array
#include<bits/stdc++.h>
using namespace std;
void print(vector<int>&list){
    for(int i=0;i<list.size();i++){
        cout << list[i] << " ";
    }
    cout << endl;
}
void find(int ind, vector<int>&list, int n, vector<int>&a){
    if(ind >= n){
        print(list);
        return;
    }
    list.push_back(a[ind]);
    find(ind+1,list,n,a );
    list.pop_back();
    find(ind+1,list,n,a);
}
int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    vector<int>Dummy;
    find(0,Dummy,n,a);
    return 0;
}