#include<bits/stdc++.h>
using namespace std;
class Solution{
    public :
    vector<int> primesInRange(vector<vector<int>> &queries){
        if(queries.empty()) return {};
        // pehla step -> find max value among all the queries
        // kyoki wahi tak ki sieve ham log banayege
        int maxvalue = 0;
        for(auto & q : queries){
            maxvalue = max(maxvalue, q[1]);
        }
        // step -2 generate all prime numbers ip to the maxvalue of the queries
        // yaha pe lagayege sieve of eras.. ka concept 
        vector<bool> isprime(maxvalue+1,true);
        /// initially sabko true mark kardo
        isprime[0] = isprime[1] = false;
        // kyoki both 0 and 1 are not prime numbers
        for(int i=2 ; i*i <= maxvalue ; i++){
            if(isprime[i]){
                for(int j = i*i; j<= maxvalue ; j++){
                    // jo element prime hai uske sare multiples ko false mark kardo till maxvalue or i*i <= maxvalue
                    isprime[j] = false;
                }
            }
        }
        // ek prefix sum array bana lenge jaha pe primecount[i] = mnumber of primes<= i 
        // us particular i tak kitne primes a chuke hai ye pata lagega is rpefix sum array se
        vector<int>primecount(maxvalue+1,0);
        for(int i=1;i<=maxvalue;i++){
            primecount[i] = primecount[i-1];
            if(isprime[i]) primecount[i]++;
        }

        // answer each query effectively using prefix sum array we just made
        vector<int>result;
        for(auto & q : queries){
            int L = q[0];
            int R = q[1];
            // primes in the range [L,R] = primes upto R - primes upto (L-1);
            int primeinrange = primecount[R] - (L>0 ? primecount[L-1] : 0);
            result.push_back(primeinrange);
        }
        return result;
    }
    
};
int main(){
    // example queries
    vector<vector<int>> queries = {
        {1,10},
        {10,20},
        {1,100}
    };

    Solution sol;
    vector<int> ans = sol.primesInRange(queries);
    cout << "Number of primes in each range : " ;
    for(int x : ans) cout << x << " ";
    cout << endl;
    return 0;
}