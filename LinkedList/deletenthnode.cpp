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
Node* deletenode(Node* head, int k){
    if(head == nullptr){
        return head;
    }
    if(k==1){
        // agar head hi delete karna hai to
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* prev = head;
    for(int i=1 ; i < k-1 && prev != nullptr; i++){
        prev = prev->next;
        // agar hame nth ko delete karna hai to we need to first reach one step behind it
    }
    if(prev== nullptr || prev->next == nullptr){
        // iska matlab k out of bound hai 
        return head;
    }
    Node* delnode = prev->next;
    prev->next = delnode->next;
    delete delnode;
}
void printLL(Node* head){
    Node* temp = head;
    while(temp!= NULL){
        cout << temp->data << " " ;
        temp= temp->next;
    }
    cout << endl;
}


int main(){
    vector<int>arr = {1,2,3,4};
    Node* head = makeLL(arr);
    deletenode(head,2);
    printLL(head);
    return 0;
}