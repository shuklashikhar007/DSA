#include<iostream>
#include<vector>
#include<map>
using namespace std;
vector < int> FindUnion(int arr1[] , int arr2[] ,  int n , int m){
    vector<int>Union;
    map<int,int>mpp;
    for(int i=0;i<n;i++){
        mpp[arr1[i]++]; // hash the first array 
    }
    for(int i=0;i<m;i++){
        mpp[arr2[i]++]; // hash the second array 
    }
    for(auto & it : mpp){ // syntax to itrate over a map 
        Union.push_back(it.first);
    }
    return Union;
}

int main(){
    int n = 10, m = 7;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 4, 4, 5, 11, 12};
    vector < int > Union = FindUnion(arr1 , arr2, n, m);
    cout << "Union of arr1 and arr2 is " << endl;
    for (auto & val: Union)
        cout << val << " ";
    return 0;
}