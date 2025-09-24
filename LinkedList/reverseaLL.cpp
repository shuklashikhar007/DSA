// to reverse a single LL
#include<bits/stdc++.h>
using namespace std;
class Node{
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
Node* makeLL(vector<int> arr){
    Node* head = new Node((arr[0]));
    Node* temp = head;
    int n = arr.size();
    for(int i=1;i<n;i++){
        Node* newnode = new Node((arr[i]));
        temp->next = newnode;
        temp = newnode;
    }
    return head;
}
Node* reverseLL(Node* head){
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        // next node to front mai store jarrur kare to preserve the reference
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
void printLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){
    vector<int> arr = {1,3,2,5};
    Node* head = makeLL(arr);
    printLL(head);
    Node* head2 = reverseLL(head);
    printLL(head2);
    return 0;
}