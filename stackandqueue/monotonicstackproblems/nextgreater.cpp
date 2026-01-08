#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<int> NGE(vector<int>& nums){
        stack<int>st;
        int n  = nums.size();
        vector<int>NGE(n);
        // abb yaha pe right to left jayenge ham
        for(int i=n-1; i>= 0;i--){
            while (!st.empty() && st.top() <= nums[i] )
            {
                st.pop();
            }
            NGE[i] = st.empty() ? -1 : st.top(); 
            st.push(nums[i]);
        }
        return NGE;
    }
};
int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    Solution sol;
    for(int i=0;i<n;i++) cin >> a[i];
    vector<int>ans = sol.NGE(a);
    for(int x : ans){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}