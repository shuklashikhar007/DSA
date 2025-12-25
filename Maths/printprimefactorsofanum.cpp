#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

void printPrimeFactors(int n) {
    if (n <= 1) return;

    // Step 1: Print all factors of 2
    while (n % 2 == 0) {
        cout << 2 << " ";
        n /= 2;
    }

    // Step 2: Check odd factors from 3 to sqrt(n)
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }

    // Step 3: If n is still > 1, it is prime
    if (n > 1) {
        cout << n << " ";
    }
}

int main(){
    int n;
    cin  >> n;
    printPrimeFactors(n);
    return 0;
}