#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

int main(){
    vector<int> arr = {2,5,8,7};
    Node * head = new Node(arr[0]);
    // pehli node bana do
    Node* current = head;
    // pointer jisse last node jo add ki hai uska track rakhe

    for(int i = 1;i< arr.size();i++){
        Node* newNode = new Node(arr[i]);
        current->next = newNode; // change the thing to which the pointer points from the location of prev node  to the location of the next node
        current = newNode;
    }

    Node * temp = head;
    while(temp != nullptr){
        cout << temp->data << " -> " ;
        temp = temp->next;
    }
    cout << "NULL\n";
    return 0;
}