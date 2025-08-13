// code to insert a new element(Node) at the starting of a single linked list ( 1D ).

#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* next;

    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};
void printLL(Node * head){
    while(head != NULL){
        cout << head->data << " "; // head ke andar jo data hai use print karo 
        head = head->next; // head ko age badhao
    }
}

Node* insertHead(Node* head, int val){
    Node* temp = new Node(val,head);
    return temp;
}

int main(){

    vector<int> arr = {12,8,5,7};
    int val = 100;

    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head = insertHead(head, val); // here we are actually redefining head 
    // abb naya head new element store karne wala head hai
    printLL(head);
    return 0;
}