#include<bits/stdc++.h>
using namespace std;
string frequencySort(string s){
    unordered_map<char , int> freq;
    // is mapp mai freq aur wo freq kis char ki hai wo store karege 
    for(char ch : s){
        freq[ch]++; // ch char ki freq badha do  
    }
    // store in a vector of pairs taki baad mai sort kar paye
    vector<pair<char , int>> vec(freq.begin(), freq.end());
    
    // step - 3 
    // Sort the pair vector by frequency (ascending or descending ) as you wish
    sort(vec.begin(), vec.end() , [](pair<char , int> & a, pair <char , int > &b){
        return a.second > b.second; // higher wali freq pehle ayegi
    });

    // ab we can build up the result stirng 
    string result = "";
    for(auto & it : vec ){
        result += string(it.second, it.first); // repeat it.first it.second times 
    }
    return result;
}
int main(){
    string s = "tree";
    cout << "Sorted by frequency : " << frequencySort(s) << endl;
    return 0;
}