// channi ( sieve of erastho to count prime numbers )
#include<bits/stdc++.h>
using namespace std;
vector<int> primes(int n){
    // function to return an array which will tell whether a number of prime ornot in O(1)
    vector<int>isprime(n+1,1); // initially sabko 1
    for(int p = 2; p*p <= n ; p++){ // root p tak jayege
        if(isprime[p]){
            // agar ye number 1 marked hai to iske sare factors ko 0 mark kardo
            for(int i=p*p ;i<=n;i++){
                isprime[i] = 0;
            }
        }
    }
    // end mai sirf prime's hi one mark honge
    //abb ek prefix sum array bana lenge to count no of primes till that number
    vector<int>pcount(n+1,0);
    for(int i=1;i<=n;i++){
        pcount[i] = pcount[i-1];
        // pehle to pichla count carry forward karlo then
        // agar curr no prime hai to increase count by 1
        if(isprime[i]){ // a
            pcount[i]++;
        }
    }
}
int main(){

    return 0;
}