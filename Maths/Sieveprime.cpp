#include<bits/stdc++.h>
using namespace std;
const int N = 100000;
int main(){
    vector<bool>isprime(N+2,true);
    isprime[0] = isprime[1] = false;
    // sieve of erasthonese
    // 2 se leke root N tak jayegi hamari sieve of erasthonese 
    for(int i=2;i*i<=N;i++){
        if(isprime[i]){
            for(int j=i*i;j<=N;j+=i){
                isprime[j] = false;
            }
        }
    }
    vector<int>nextprime(N+2);
    int last = -1;
    for(int i=N ; i>=0 ; i--)
    {
        if(isprime[i]){
            last = i;
        }
        nextprime[i] = last; 
    }    
    
    return 0;
}