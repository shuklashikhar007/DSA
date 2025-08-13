// how to delete a node at the end of a linked list 
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
void printLL( Node * head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}
Node* deleteTail(Node* head){
    // agar list mai kuch nahi hai ya sirf ek node hai to 
    // return NULL 
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    // ek temporary pointer bana lo list ko traverse karne ke liye
    Node * temp = head;
    // traverse to the second last node in the linked list 
    while(temp -> next -> next != NULL){
        temp = temp->next;
    }
    // temp hold the acces to the last node now 
    // delete the last node now
    delete temp->next;
    // second last wale ke next ko nullptr set kardo
    // effectively terminating the linked list
    temp->next = nullptr;
    // return the head of the modified list
    return head;
}



int main(){
    vector<int> arr = {12,5,8,7};
    // create a linked list with the values
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    // call the delete tail function to delete the last node 
    head = deleteTail(head);
    printLL(head);
    return 0;
}