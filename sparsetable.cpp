#include<bits/stdc++.h>
using namespace std;
int main(){
    
    return 0;
}
struct SparseTable {

    vector<vector<int>> stMin, stMax;
    vector<int> lg;
    int n, LOG;

    SparseTable(vector<int>& a) {

        n = a.size();

        // lg[i] = floor(log2(i))
        lg.resize(n + 1);
        for(int i = 2; i <= n; i++) {
            lg[i] = lg[i / 2] + 1;
        }

        LOG = lg[n] + 1;

        stMin.assign(LOG, vector<int>(n));
        stMax.assign(LOG, vector<int>(n));

        // level 0
        for(int i = 0; i < n; i++) {
            stMin[0][i] = a[i];
            stMax[0][i] = a[i];
        }

        // build
        for(int j = 1; j < LOG; j++) {

            for(int i = 0; i + (1 << j) <= n; i++) {

                stMin[j][i] = min(
                    stMin[j - 1][i],
                    stMin[j - 1][i + (1 << (j - 1))]
                );

                stMax[j][i] = max(
                    stMax[j - 1][i],
                    stMax[j - 1][i + (1 << (j - 1))]
                );
            }
        }
    }

    int queryMin(int l, int r) {

        int len = r - l + 1;
        int p = lg[len];

        return min(
            stMin[p][l],
            stMin[p][r - (1 << p) + 1]
        );
    }

    int queryMax(int l, int r) {

        int len = r - l + 1;
        int p = lg[len];

        return max(
            stMax[p][l],
            stMax[p][r - (1 << p) + 1]
        );
    }

    long long queryDiff(int l, int r) {

        return 1LL * queryMax(l, r) - queryMin(l, r);
    }
};