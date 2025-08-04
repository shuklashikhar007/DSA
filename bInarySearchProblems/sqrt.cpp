

#include <bits/stdc++.h>
using namespace std;

int floorSqrt(int n) {
    int low = 1, high = n;
    //Binary search on the answers:
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long val = mid * mid;
        if (val <= (long long)(n)) {
            //eliminate the left half: because hame largest possible value chaiye as our answer.
            low = mid + 1;
        }
        else {
            //eliminate the right half:
            high = mid - 1;
        }
    }
    return high;
}

int main(){
    int n;
    cin >> n;
    cout << "The square root (nearest) of the number n is : " << floorSqrt(n) << endl;
    return 0;
}