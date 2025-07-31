#include <bits/stdc++.h>
using namespace std;

vector<int> find(vector<int> &arr) {
    vector<int> ans;
    int n = arr.size();
    map<int, int> mpp;

    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }

    for (int i = 1; i <= n; i++) {
        if (mpp[i] == 2) {
            ans.push_back(i);  
        }
        if (mpp[i] == 0) {
            ans.push_back(i);  
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 3, 3, 5, 6, 7, 8}; // missing: 4, repeated: 3
    vector<int> ans = find(arr);

    cout << "The repeated element is: " << ans[0] << "\n";
    cout << "The missing number is: " << ans[1] << "\n";

    return 0;
}
