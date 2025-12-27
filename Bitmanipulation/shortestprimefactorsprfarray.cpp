// creating a shortest prime factor (SPF) array using sieve concept
#include<bits/stdc++.h>
using namespace std;
#define N 100000
vector<int> SPF(N + 1, 1);

int main(){
    for(int i=0;i<=N;i++){
        SPF[i]= i; // initially sabka smallest prime number khudhonga
    }
    for(int i=2;i*i<=N;i++){
        if(SPF[i] == i){
            // mark all its factors with itself
            for(int j = i*i; j<= N;j+=i){
                // inc j by i 
                if(SPF[j] == j){
                    SPF[j] = i;
                    // mark that value with this number
                }
            }
        }
    }
    return 0;
}