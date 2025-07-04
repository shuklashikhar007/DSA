// in this module we learned how to replace all the spaces present in a string with a particular char or some special value.
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<string>
using namespace std;
int main(){
    string s1;
    cout << "Enter the  string : " << endl;
    getline(cin,s1);
    string add;
    cout << "Enter the char to replace the spaces : " << endl;
    cin >> add;
    stringstream ss(s1);
    string word;
    vector<string>words;
    while(ss >> word){
        words.push_back(word);
    }
    // jo string enter kari uske sare spaces ignore karke hamne sare words ko ek vector mai store karwa liya 
    string ans;
    for(int i=0;i<words.size();i++){
        ans += words[i];
        ans += add;
    }
    cout << ans ;
    return 0;
    // for multiple spaces we can make an array of all the index's where space is present and then add the char in all those locations 
}