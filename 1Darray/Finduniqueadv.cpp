#include<iostream>
using namespace std;
// this code shows that the method works only if repetitions are in multiples of two in the array.
int findunique( int arr[] , int size){
    int ans = 0;
    for(int i=0;i<size;i++){
        ans = ans ^ arr[i]; // update the value of ans by taking 
    }
    return ans;
}
int main(){
    int arr[11] = {1,1,1,1,2,2,2,2,8,4,4}; // the unique element is 8
    cout << "The unique element is : " << findunique(arr,11) << endl;
    return 0;
}