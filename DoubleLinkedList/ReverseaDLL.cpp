#include<bits/stdc++.h>
using namespace std;
class Node{
public :
    int data;
    Node* next;
    Node* back;

    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};
Node* convertarr2DLL(vector<int>arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    // abb banayege ek DLL
    for(int i=1; i < arr.size() ; i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}
Node* reverseDLL(Node* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    Node* prev = NULL;
    Node* curr = head;
    while(curr != NULL) {
        Node* front = curr->next;
        curr->next = prev;
        curr->back = front;
        prev = curr;
        curr = front;
    }
    return prev;
}
void printLL(Node * head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data;
        temp = temp->next;
    }
}    
int main(){
    vector<int> arr = {12, 5, 8, 7};
    Node* head = convertarr2DLL(arr);
    printLL(head);
    Node* head2 = reverseDLL(head);
    printLL(head2);
    return 0;
}