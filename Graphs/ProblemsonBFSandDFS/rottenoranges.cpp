#include<bits/stdc++.h>
using namespace std;
int orange(vector<vector<int>> &grid){
    if(grid.empty()) return 0;
    int m = grid.size();
    int n = grid[0].size();
    int t = 0; // total time jo beet gaya
    int tot = 0; // total no of orange( fresh + rot)
    int cnt = 0; // kitne rot hogaye during the process
    queue<pair<int,int>> rotten;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] != 0){
                tot++; // total valid oranges
            }
            if(grid[i][j] == 2){
                rotten.push({i,j}); // push all the locations of rotten oranges
            }
        }
    }
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    // BFS traversal jab tak sare possible fresh oranges rot na hojaye
    while (!rotten.empty())
    {
        int k = rotten.size();
        cnt += k;

        while (k--)
        {
            int x = rotten.front().first;
            int y = rotten.front().second;
            rotten.pop();

            // sari 4 direction mai check karo
            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || ny < 0 || nx >= m || ny >= n ||grid[nx][ny] != 1){
                    continue;
                } //
                // sirf tabhi run hoga jab grid[nx][ny] == 1 hai 
                // mark the fresh as rotten
                grid[nx][ny] = 2;
                rotten.push({nx,ny});
            }
            // abb agar sare neigh traverse karne ke baad new neigh added to queue then

            if(!rotten.empty()){
                t++; // to hame number of days badhane honge
            }
        }
    }
    // agar sare oranges rot hogaye to time else we return -1
    // it was not possible to rot all of them

    return tot == cnt ? t : -1;    
}
int main(){
     // Input grid with 2 = rotten, 1 = fresh, 0 = empty
    vector<vector<int>> v{{2, 1, 1}, 
                          {1, 1, 0}, 
                          {0, 1, 1}};
    
    // Call the function to calculate minimum time required
    int rotting = orange(v);

    // Output the result
    cout << "Minimum Number of Minutes Required " << rotting << endl;

    return 0;
   
}