#include<bits/stdc++.h>
using namespace std;
vector<int> leaders(int arr[] , vector<int> ans, int size){
    int max = arr[5] ; // first element from the back will always be a leader element 
    ans.push_back(max);
    for(int j=4;j>=0;j--){
        if(arr[j] > max){
            ans.push_back(arr[j]);
            max = arr[j];
        }
    }
    return ans;
}
int main(){
    int arr[6] = {10,22,12,3,0,6};
    vector<int>ans;
    leaders(arr,ans,6);
    cout << "The leader elements are : " << endl;
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " " ;
    }


    return 0;
}