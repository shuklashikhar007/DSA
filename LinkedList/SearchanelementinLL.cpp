#include<bits/stdc++.h>
using namespace std;
class Node {
    public :
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

int checkpresent(Node* head, int desired){
    Node* temp = head;

    while(temp != nullptr){
        // yaha pe puri linked list ko traverse karege 
        if(temp->data == desired){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main(){

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    int val = 3;
    cout<< checkpresent(head,val)<< endl;

    return 0;
}