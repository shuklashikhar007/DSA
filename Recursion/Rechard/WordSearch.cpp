// DFS ka question
/*
class Solution {
public:
    int drow[4] = {-1,0,1,0};
    int dcol[4] = {0,1,0,-1};

    bool dfs(int r, int c, int ind,
             vector<vector<char>> &board,
             vector<vector<int>> &vis,
             string &word){

        // pura word match hogaya
        if(ind == word.size()){
            return true;
        }

        int m = board.size();
        int n = board[0].size();

        // niche likhe 3 check mai se agar ek bhi true hai
        // that means in searching all 4 directions we went out of the grid
        if(r < 0 || c < 0 || r >= m || c >= n){
            return false;
        }

        // koi cell already visited hai means already used hai
        // to we cannot use it again to return
        if(vis[r][c] == 1) return false;

        // agar current row col pe cell does not match
        // the corresponding word in the string return false;
        if(board[r][c] != word[ind]){
            return false;
        }

        // agar sari conditions satisfied to mark visited
        vis[r][c] = 1;

        // abb 4 possible directions mai check karege
        for(int i = 0; i < 4; i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            if(dfs(nrow, ncol, ind + 1, board, vis, word)){
                return true;
            }
        }

        // ye backtracking karne ka reason ->
        // agar is path se answer nahi mila to
        // cell ko unvisited bana denge
        vis[r][c] = 0;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        // har ek cell se DFS start karke try karege
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(dfs(i, j, 0, board, vis, word)){
                    return true;
                }
            }
        }
        return false;
    }
};




*/