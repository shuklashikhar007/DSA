// CP ke liyeimp hai
// to find all divisor's of a number
// logic we apply
/*

1 × n
2 × n/2
3 × n/3
...
√n × √n   ← middle point
...
Once you cross √n, you're just seeing mirror factors of ones you've already checked.

*/
// ek number ka atmost ek hi factor sqrt(n) se bada ho sakta hai to agar sqrt(n) tak iterate karne pe koi factor nahi mila 
// that means the number itself is prime since ek hi factor hai root n se badathat will be the number itself

// code
#include<bits/stdc++.h>
using namespace std;
vector<int>divisors(int n){
    vector<int>ans;
    int sqrtN = sqrt(n);
    for(int i=1;i<= sqrtN;i++){
        if(n%i == 0){
            ans.push_back(i);
        }
        if(i != n/i){
            ans.push_back(n/i); // complementary factor ko add kardo agar wo i nahi hai to
            // agar i hua to duplicate hojayege that's why we do a check here
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}
int main(){
    return 0;
}
