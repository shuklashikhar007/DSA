#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    vector<int>NSE(n);
    // nearest smallest on the left side store karne ke liye 
    stack<int>st;
    for(int i=0;i<n;i++){
        // jabtak stack bhara hua hai and the topmost is greater than current keep poping
        // while (st.top() >= a[i] && !st.empty()) -> ESE KABHI MAT LIKHNA order matters
        while (!st.empty() && st.top() >= a[i])
        {
            st.pop();
        }
        // agar stack khali hogaya to matlab NSE not available
        NSE[i] = st.empty() ? -1 : st.top();
        // at last push element in stack
        st.push(a[i]);
    }
    for(int i=0;i<NSE.size();i++){
        cout << NSE[i]  << " " ;
    }
    cout << endl;
    return 0;
}