#include <bits/stdc++.h>
using namespace std;
int main(){
    string main;
    string remove;
    cout << "Enter the main string : " << endl;
    getline(cin,main);
    cout << "Enter the substring to remove : " << endl;
    getline(cin,remove);
    while(main.length() != 0 && main.find(remove)  < main.length() ){
        main.erase(main.find(remove), remove.length());
    }
    cout << main;
    // string.erase ( index to start from , length to erase )
    // string.find(substringtofind) this inbuilt function returns the index where the substring is located if found else it returns false.
    return 0;
}