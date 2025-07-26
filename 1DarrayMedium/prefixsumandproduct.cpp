#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {2, 3, 5, 4};
    int n = arr.size();

    // Prefix Sum and Product
    vector<long long> prefixSum(n);
    vector<long long> prefixProduct(n);

    prefixSum[0] = arr[0];
    prefixProduct[0] = arr[0];

    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
        prefixProduct[i] = prefixProduct[i - 1] * arr[i];
    }

    // Suffix Sum and Product
    vector<long long> suffixSum(n); // piche side se ana 
    vector<long long> suffixProduct(n);

    suffixSum[n - 1] = arr[n - 1];
    suffixProduct[n - 1] = arr[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        suffixSum[i] = suffixSum[i + 1] + arr[i];
        suffixProduct[i] = suffixProduct[i + 1] * arr[i];
    }

    // Output all arrays
    cout << "Original Array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    cout << "Prefix Sum: ";
    for (long long x : prefixSum) cout << x << " ";
    cout << "\n";

    cout << "Prefix Product: ";
    for (long long x : prefixProduct) cout << x << " ";
    cout << "\n";

    cout << "Suffix Sum: ";
    for (long long x : suffixSum) cout << x << " ";
    cout << "\n";

    cout << "Suffix Product: ";
    for (long long x : suffixProduct) cout << x << " ";
    cout << "\n";

    return 0;
}
