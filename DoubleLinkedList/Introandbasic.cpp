#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data; // data stored in the node 
    Node* next; // pointer to the next node in the list (forward direction)
    Node* back; // pointer to the previous node in the list (backward direction)

    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1; // single LL se yahi differnece hai ki yaha ek back pointer bhi hai
    }

    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr; // Double LL mai we have a back pointer as well
    }
};
int main(){










    return 0;
}