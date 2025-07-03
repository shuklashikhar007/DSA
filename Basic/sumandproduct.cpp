#include<iostream>
using namespace std;
int main(){
    int n =0;
    int sum = 0;
        int product = 1;
        while(n>0){
            int digit = n%10;
            sum += digit;
            product *= digit;
            n = n/10;
        }
        return product - sum;
    return 0;
}