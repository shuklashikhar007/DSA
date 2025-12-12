// Best time to buy and sell stock - 1
// ye bina DP ke ho jaygea
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    int mini = INT_MAX;
    int profit = INT_MIN;
    for(int i=0;i<n;i++){
        mini = min(mini, arr[i]); // min trace karo 
        profit = max(profit , arr[i] - mini);
    }
    cout << profit << endl;
    return 0;
}