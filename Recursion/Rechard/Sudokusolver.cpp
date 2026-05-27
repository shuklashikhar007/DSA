#include<bits/stdc++.h>
using namespace std;
bool isvalid(vector<vector<char>> &board, int row , int col , char num){
    for(int k = 0; k < 9 ; k++){
        if(board[row][k] == num && k != col){
            return false;
        }
        if(board[k][col] == num && k != row){
            return false;
        }
        int r = 3*(row/3) + k/3;
        int c = 3*(col/3) + k%3;
        if(board[r][c] == num){
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<char>> &board, vector<pair<int,int>> &emp, int idx){
    if(idx == emp.size()){
        return true;
    }
    int r = emp[idx].first;
    int c = emp[idx].second;
    // abb we will try placing numbers from 1 to 9 in each khali cell
    for(char num = '1' ; num <= 9 ; num++){
        if(isvalid(board, r,c,num)){
            board[r][c] = num;
            if(solve(board,emp,idx+1)){
                return true;
            }
            board[r][c] = '.'; // backtracking 
        }
    }
    return false; // koi bhi num fit nahi hua to backtrack karo
}
void solveSudoku(vector<vector<char>>& board) {
        vector<pair<int,int>> emptyCells;
        // store all empty cells
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                    emptyCells.push_back({i, j});
                }
            }
        }
        solve(board, emptyCells, 0);
    }
int main(){

    return 0;
}