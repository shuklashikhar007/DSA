#include<bits/stdc++.h>
using namespace std;
vector<int>manacher(string s){
    int n = s.size();
    vector<int>d1(n);
    int l = 0;
    int r = -1;
    for(int i=0;i<n;i++){
        int k;
        if(i>r){
            // i r ke bahar chala gya 
            k=1;
        }
        else{
            int mir = l + r - i;
            k = min(d1[mir],r-i+1);
        }
        while(
            i-k >= 0 && i + k < n && s[i-k] == s[i+k]
        ){
            k++;
        }
        d1[i] = k;
        if(i + k - 1 > r){
            l = i - k + 1;
            r = i + k - 1;
        }
    }
    // total odd length palindrome nikalne ke liye add all the values
    return d1;
}
vector<int>evenman(string s){
    int n = s.length();
    vector<int>d2(n);
    int l = 0, r = -1;
    for(int i=0;i<n;i++){
        int k;
        if(i>r){
            k = 0;
        }
        else{
            int mir = l + r - i + 1;
            k = min(d2[mir], r-i+1);
        }
        while (i-k-1 >= 0 && i + k < n && s[i-k-1] == s[i+k])
        {
            k++;
        }
        d2[i] = k;
        if(i+k-1>r){
            l = i-k;
            r = i + k - 1;
        }
    }
    return d2;
}
int main(){

    return 0;   
}