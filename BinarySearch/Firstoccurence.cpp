#include<bits/stdc++.h>
using namespace std;
int solve (int n, int key , vector<int> &v){
    int start = 0;
    int end = n -1 ;
    int res = -1;

    while(start <= end){
        int mid = (start+end)/2;
        if(v[mid] == key){
            res = mid;
            start = mid + 1;
        }
        else if(key < v[mid]){
            end = mid - 1;
        }
        else{
            // ye wo wala case hai jab v[mid]  key se chota hoga 
            start = mid + 1;
        }
    }
    return res;
}
int main(){
    int n = 7;
    int key = 13;
    vector<int> v = {3,4,13,13,13,20,40};
    cout << solve (n,key,v) << endl;


    return 0;
}