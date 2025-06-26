#include<iostream>
using namespace std;

int binarysearch(int arr[], int key, int size){
    int s = 0;
    int e = size - 1;
    int mid = s + (e-s)/2;
    while(s<=e){
        if(arr[mid] == key){
            return 1;
        }
        else if(key > arr[mid]){
            s = mid + 1;
        }
        else if(key < arr[mid]){
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return 0;
}
int main(){
    
    int arr[5];
    cout<< "Enter the elements : " << endl;
    for(int i= 0 ; i <5 ;i++){
        cin >> arr[i];
    }
    cout << "Enter the element to search for : " << endl;
    int key;
    cin >> key;
    int boolean = binarysearch(arr,key,5);
    if(boolean){
        cout << "Element Found ! "<< endl;
    }
    else if(!boolean){
        cout << "Element not Found !! " << endl;
    }
    return 0;
}