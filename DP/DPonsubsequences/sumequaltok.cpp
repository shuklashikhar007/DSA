// recursion + memoization approach
#include <bits/stdc++.h>
using namespace std;
bool recursion(int index, int target, vector<int> &arr, vector<vector<int>> &dp) {
    if (target == 0) return true;  // Empty subset gives sum 0
    if (index == 0) return (arr[0] == target);
    if (dp[index][target] != -1)
        return dp[index][target];
    bool notpick = recursion(index - 1, target, arr, dp);
    bool pick = false;
    if (arr[index] <= target)
        pick = recursion(index - 1, target - arr[index], arr, dp);

    return dp[index][target] = (pick || notpick);
}
bool check(vector<int> &arr, int target) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return recursion(n - 1, target, arr, dp);
}
int main() {
    vector<int> arr = {2, 3, 1, 1};
    int target = 8;
    bool kya = check(arr, target);
    if (kya)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
