#include<bits/stdc++.h>
using namespace std;
int lowerbound(const vector<int> &row, int target){
    int low = 0;
    int high = row.size() - 1;
    int ans = row.size();
    while(low <= high){
        int mid = low + (high - low)/2;
        if(row[mid] >= target){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}
int rowwithmaxOnes(vector<vector<int>> & matrix){
    int n = matrix.size(); // number of rows
    int m = matrix[0].size(); // number of columns
    int cnt_max = 0;
    int index = -1;
    for(int i=0;i<n;i++){
        int firstone = lowerbound(matrix[i],1);
        int numberofones = m - firstone;
        if(numberofones > cnt_max){
            cnt_max = numberofones;
            index = i;
        }
    }
    return index;
}
int main(){
    vector<vector<int>> matrix = {
        {0,0,1,1},
        {0,1,1,1},
        {0,0,0,1}
    };
    int result = rowwithmaxOnes(matrix);
    cout << "Row with the max no of ones is : " << result << endl;
    return 0;
}