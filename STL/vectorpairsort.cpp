// Codeforces problem on vector pair sorting + greedy + binary search(1300)
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];
        vector<pair<int,int>> values;
        for(int i = 0; i < n; i++){
            if(arr[i] - (i+1) < 0){
                values.push_back({arr[i], i+1});
            }
        }
        sort(values.begin(), values.end(),
             [](auto &a, auto &b){
                 return a.second < b.second;
             });
        vector<int> firsts;
        for(auto &p : values) firsts.push_back(p.first);
        sort(firsts.begin(), firsts.end());
        long long pairs = 0;
        for(auto &p : values){
            pairs += firsts.end() - upper_bound(firsts.begin(), firsts.end(), p.second);
        }
        cout << pairs << '\n';
    }
    return 0;
}