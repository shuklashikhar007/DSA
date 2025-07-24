// in this code we will learn how to find a unique element in a array where are elements are repeated twice ( or even no of times ) and only one element is unique and is present once 
// 
#include<iostream>
using namespace std;
// XOR Table - > 
// 0 ^ 0 = 0
// 0 ^ 1 = 1
// 1 ^ 0 = 1
// 1 ^ 1 = 0
// gices true value only when either og the two parameters is present (1);
int findunique(int arr[], int size){
    int ans = 0;
    for(int i = 0;i<size;i++){
        ans = ans ^ arr[i];
    }
    return ans; // XOR of a element with itself is 0 and they cancel each other so in the end only the unique one is left.
}
int main(){
    int arr[7] = {1,1,2,2,3,4,4};
    cout << "The unique element of the array is : " << findunique(arr,7) << endl;
    return 0;
}