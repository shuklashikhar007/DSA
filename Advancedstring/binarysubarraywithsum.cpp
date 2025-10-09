#include <bits/stdc++.h>
using namespace std;
// ye approach likh ke samjhna baad mai kafi acchi approach haiye
// logic -> subaaryas with sum === goal = atmost(goal) - atmost(goal - 1);
// Helper function: count number of subarrays with sum <= goal
// atmost wali approach yaha isliye kaam kar rahi hai since we have a binary array
// agar array binary nahi hoti to we cannot apply this approach since only in case of binary numbers will increase and decrease
// by a single value baki case mai there can be sudden increase or decrease 

int atMost(vector<int>& arr, int goal) {
    if (goal < 0) return 0;
    int left = 0, sum = 0, count = 0;
    for (int right = 0; right < arr.size(); right++) {
        sum += arr[right];
        while (sum > goal) {
            sum -= arr[left];
            left++;
        }
        count += (right - left + 1); // all subarrays ending at 'right'
    }
    return count;
}

// Final function: subarrays with sum == goal
int output(vector<int> arr, int goal) {
    return atMost(arr, goal) - atMost(arr, goal - 1);
}

int main() {
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;
    cout << output(nums, goal) << endl; 
    return 0;
}
