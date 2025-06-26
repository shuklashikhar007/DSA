#include<iostream>
#include<vector>
using namespace std;
int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    vector<int>P;
    int key;
    cout << "Enter the value to find pairs which when added give the value : " << endl;
    cin >> key;
    for(int i=0;i<10;i++){
        for(int j=i+1;j<10;j++){
            if(arr[i] + arr[j] == key){
                P.push_back(arr[i]);
                P.push_back(arr[j]);
            }
        }
    }
    for(int i=0;i<P.size();i++){
        cout << P[i] << " ";
    }
    return 0;
}