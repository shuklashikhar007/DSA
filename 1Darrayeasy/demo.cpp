#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[7] = {1,1,2,2,2,3,3};
    int i = 0;
    int n = 7;
    for(int j = 1 ; j < n ;j ++){
        if(arr[i] != arr[j]){ // pehla element mila jo same nahi hai
            arr[i+1] == arr[j];
            i++; // i ko tabhi hi badhana hai jab replace karo 
        }
    }
    cout << "The size of the longest array not containing duplicate and sorted is   : " << i + 1;
    return 0;
}