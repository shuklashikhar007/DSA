// achha tarika ( optimal method )
#include<bits/stdc++.h>
using namespace std;
bool checkbit(int n , int bit){
    // bit masking se ye kaam O(1) mai ho jayega
    
    int bitmask = 1 << bit;
    int flag = n & bitmask;;

    if(flag != 0){
        // iska matlab ith bit ( 0 based indexing was 1)
        return true;
    }
    else{
        // 0 aya matlab ith bit was 0
        return false;
    }
}
int main(){
    int n, bit;
    cin >> n >> bit;
    bool check = checkbit(n,bit);
    if(check) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}