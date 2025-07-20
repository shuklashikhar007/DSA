#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int> &v, int low , int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    
    while(left <= mid && right <= high){
        if(v[left] <= v[right]){
            temp.push_back(v[left]);
            left++;
        }
        else{
            temp.push_back(v[right]);
            right++;  
        }
    }

    while(left <= mid){
        temp.push_back(v[left]);
        left++;
    }

    while(right <= high){
        temp.push_back(v[right]);
        right++;
    }

    for(int i = low; i <= high; i++){
        v[i] = temp[i - low];
    }
}

void MS(vector<int> &v, int low, int high){
    if(low == high) return;
    int mid = (low+high)/2;
    MS(v,low,mid); // keep partitioning the vector into two halves till the size of each half is 1.
    MS(v,mid+1,high); // 2nd partiiton recursively will be from mid + 1 to high 
    merge(v,low,mid,high); // perform merge function on the singular and ahead arrays when backtracking happens 
}
int main(){
    vector<int>v = {10,7,4,6,9,3,8,2,1,5};
    MS(v,0,9);
    cout << "The array after sorting is  : " << endl;
    for(int i=0;i<10;i++){
        cout << v[i] << " " ;
    }


    return 0;
}
