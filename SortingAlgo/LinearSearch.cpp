#include<iostream>
using namespace std;
// we write functions here 
int findelement(int arr[], int key){
    for(int i = 0;i<10;i++){
        if(arr[i] == key){
            return 1;
        }
    }
    return 0;
}

int main(){
    int arr[10];
    cout << "Enter the elements of the array : " << endl;
    for(int i=0;i<10;i++){
        cin >> arr[i];
    }
    int key;
    cout << "Enter the value to search for : " << endl;
    cin >> key;
    int ans = findelement(arr,key);
    if(ans){
        cout << " Element found in the array ! " << endl;
    }
    else if(!ans){
        cout << "Element not found in the array ! " << endl;
    }    
    return 0;
}

