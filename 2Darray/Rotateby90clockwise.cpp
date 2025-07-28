#include<bits/stdc++.h>
using namespace std;
vector < vector < int >> rotate(vector<vector<int>> &matrix){
    int n = matrix.size();
    vector < vector < int >> rotated(n , vector < int > (n,0));
    for(int i = 0; i < n ; i++){
        for(int j = 0;j<n;j++){
            rotated[j][n-i-1] = matrix[i][j];
        }
    }
    return rotated;
}
int main(){
    vector<vector<int>>arr;
    arr = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> rotated = rotate(arr);
    cout << "Rotated Image : " << endl;
    int n = rotated.size();
    int m = rotated[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){  
            cout << rotated[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}