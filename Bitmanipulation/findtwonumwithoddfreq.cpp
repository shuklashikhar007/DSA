#include<bits/stdc++.h>
using namespace std;
using ll = long long;
// to make only the rightmost bit 1 and rest all but o use
// rightmost = (num & (num-1)) ^ num
vector<int> find(vector<int>&a){
    int n = a.size();
    ll XOR = 0;
    for(int i=0;i<n;i++){
        XOR = XOR^a[i];
    }
    int rightmost = (XOR & (XOR-1)) ^ XOR;
    int xor1 = 0, xor2 = 0;
    // numbers ko 2 group mai baant lo 
    // ek group jisme ye rightmost bit set hai, ek group jisme ye rightmost bit set nahi ha
    for(int i=0;i<n;i++){
        if((a[i] & rightmost) != 0){ // yaha pe end mai bit nahi value ayegi output mai
            xor1 = xor1 ^ a[i];
        }
        else{
            xor2 = xor2 ^ a[i];
        }
    }
    // order ke anusar return kardo
    if(xor1 < xor2) return {xor1, xor2};
    else return {xor2, xor1};
}
int main(){
    vector<int>nums= {1,2,1,3,5,2};
    vector<int>ans = find(nums);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}