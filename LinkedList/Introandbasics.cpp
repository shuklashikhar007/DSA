#include<bits/stdc++.h>
using namespace std;
class Node {
    public :
    int data; // custom data type mai integer data hoga
    // pointer data type
    Node* next;
    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){ // agar int main se sirf array ka element pass hua hai to 
        // ye wala constructor use hoga 
        data = data1;
        next = nullptr;
    }
};

int main(){

    vector<int> arr = {2,5,8,7};
    Node* y = new Node(arr[0], nullptr);
    cout << y-> data << endl;



    return 0;
}