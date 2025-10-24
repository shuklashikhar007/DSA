#include <bits/stdc++.h>
using namespace std;

int ninjaTraining(int n, vector<vector<int>>& points) {
    vector<int> prev(4, 0);

    // Base case: Day 0
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    // Fill for remaining days
    for (int day = 1; day < n; day++) {
        vector<int> cur(4, 0);
        for (int last = 0; last < 4; last++) {
            cur[last] = 0;
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    int point = points[day][task] + prev[task];
                    cur[last] = max(cur[last], point);
                }
            }
        }
        prev = cur; // move to next day
    }

    return prev[3];
}

int main() {
    int n = 3;
    vector<vector<int>> points = {
        {10, 40, 70},
        {20, 50, 80},
        {30, 60, 90}
    };

    cout << "Maximum Points = " << ninjaTraining(n, points) << endl;
    return 0;
}
