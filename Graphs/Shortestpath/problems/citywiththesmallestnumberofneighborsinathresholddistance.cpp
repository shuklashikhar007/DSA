#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int findcity(int n, int m, vector<vector<int>> &edges, int distanceThreshold){

        // Ek 2D dist array bana lenge to apply Floyd Warshall Algo
        // long long use karna zaroori hai kyoki path length bahut bada ho sakta hai
        vector<vector<long long>> dist(n, vector<long long>(n, 1e18));

        // har edge ka distance set kardo
        for(auto it : edges){
            // bi directional graph hai to both ways set karege edge distance
            int u = it[0], v = it[1], w = it[2];

            // agar multiple edges ho same nodes ke beech to minimum wala store karo
            dist[u][v] = min(dist[u][v], (long long)w);
            dist[v][u] = min(dist[v][u], (long long)w);
        }

        for(int i=0;i<n;i++){
            // kyoki dist of a city to itself is 0
            dist[i][i] = 0;
        }

        // abb isi distance array mai floyd warshall laga denge
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    // agar beech ka koi bhi path INF hai to skip
                    if(dist[i][k] == 1e18 || dist[k][j] == 1e18){
                        continue;
                        // matlab i se k ya k se j ke beech path exist hi nahi karta
                    }
                    dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
                }
            }
        }

        int cntcity = n;
        int cityno = -1;

        for(int city = 0; city < n; city++){
            int cnt = 0;

            for(int adjcity = 0 ; adjcity < n ; adjcity++){
                // khud ko count nahi karna
                // agar city se adjcity ka distance threshold ke andar hai to count badhao
                if(city != adjcity && dist[city][adjcity] <= distanceThreshold){
                    cnt++;
                }  
            }

            // yaha compare karna hai, inner loop ke baad
            if(cnt <= cntcity){
                cntcity = cnt;
                cityno = city;
            }
        }

        return cityno;
    }
};

int main(){
    return 0;
}
