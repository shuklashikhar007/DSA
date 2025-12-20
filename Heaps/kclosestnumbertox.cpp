#include<bits/stdc++.h>
using namespace std;
vector<int> kClosest(vector<int>& a, int k, int x) {
    priority_queue<pair<int,int>> maxh;
    for (int num : a) {
        maxh.push({abs(num - x), num});
        if (maxh.size() > k) {
            maxh.pop();  
        }
    }
    vector<int> ans;
    while (!maxh.empty()) {
        ans.push_back(maxh.top().second);
        maxh.pop();
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    vector<int> b = kClosest(arr, k, x);
    for (int i = 0; i < b.size(); i++) {
        cout << b[i] << " ";
    }
    return 0;
}
