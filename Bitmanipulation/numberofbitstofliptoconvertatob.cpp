#include<bits/stdc++.h>
using namespace std;
int minbit(int start, int goal){
    int num = start^goal;
    int cnt = 0;
    while (num)
    {
        num = num & (num-1);
        cnt++;
    }
    return cnt;
}
// 
int main(){
    int s,g;
    cin >> s >> g;
    int ans = minbit(s,g);
    cout << ans << endl;
    return 0;
}