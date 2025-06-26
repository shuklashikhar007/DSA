#include<iostream>
#include<string.h>
using namespace std;
// before strings were invented we used to use char array in C

int palindrome(char name[], int size){
    int s = 0;
    int e = size - 1;
    while(s<e){
        if(name[s] != name[e]){
            return 0;
        }
        else{
            s++;
            e--;
        }
    }
    return 1; // if we reach here it is for sure a palindrome string.
}
int main(){
    cout << "Enter your name : " << endl;
    char name[100];
    cin >> name;
    cout << "Your name is : " << name << endl;
    cout << "Your name has " << strlen(name) << " characters" << endl;
    cout << "Your name in reverse is : " << strrev(name) << endl;
    int ans = palindrome(name,strlen(name));
    if(ans){
        cout << "The string is a palindrome " << endl;
    }
    else{
        cout << "Thr string is not a palindrome " << endl;
    }
    return 0;
}