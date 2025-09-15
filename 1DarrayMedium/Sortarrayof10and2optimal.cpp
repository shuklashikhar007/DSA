#include<bits/stdc++.h>
using namespace std;
void sort(vector<int> &arr){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int mid = 0;
    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[low],arr[mid]);
            mid++;
            low++; // since purani wali low position pe 0 a jayega swap hoke so we don't need it anymore so we will move ahead 
        }
        else if(arr[mid] == 1){
            mid++; // 1 hai yaha pe that means it's already at correct position so move ahead 
        }
        else{
            // agar 2 hai yaha pe to swap it with the nearest high position and decrease the high value
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}
int main(){
    vector<int> arr = {2,2,0,1,0,1};
    sort(arr);
    for(int i=0;i<arr.size();i++){
        cout << arr[i] ;
    }

    return 0;
}