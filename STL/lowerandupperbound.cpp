// search the lower bound of a element in a array  
// pehla index i where arr[i] >= the target is the lower bound
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&arr,int target){
    int n = arr.size();
    int l = 0;
    int h = n - 1;
    while (l < h)
    {
        int mid = l + (h-l)/2;
        if(arr[mid] >= target){
            h = mid;
        }
        else { // matlab agar esa hua arr[mid] < target
            l = mid + 1;
        }
    }
    return l;
}
int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n,k;
        cin >> n >> k;
        vector<int>v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        int ans = solve(v,k);
        cout << ans << endl;
    }
    
    return 0;
}
// lower bound using in built function
/*
#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> v = {1, 2, 4, 4, 4, 7, 9};

    int val = 4;

    int lb = lower_bound(v.begin(), v.end(), val) - v.begin(); // 2
    int ub = upper_bound(v.begin(), v.end(), val) - v.begin(); // 5
    int count = ub - lb; // 3 elements equal to 4

    cout << "lower_bound index = " << lb << endl;
    cout << "upper_bound index = " << ub << endl;
    cout << "Count of " << val << " = " << count << endl;
}
*/