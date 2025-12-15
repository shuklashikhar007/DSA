// if we only want to find the length of the LIS then we can use this binary search method
// isse sirf length hi pata laga sakte hai
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin >> arr[i];
    vector<int>temp;
    temp.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i] > temp.back()){
            temp.push_back(arr[i]); // arr ka element is greater than all elements present in the arr
        }
        else{
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }
    cout << temp.size() << endl;
    return 0;
}