#include<bits/stdc++.h>
using namespace std;
// steps to insert a node at the end of a Double LL
// Step - 1 -> Traverse through the LL and reach the tail of the DLL 
// Step - 2 -> Create a new Node with its data as k and back pointer pointing to tail and next pointer pointing to null 
// Step - 3 -> Update the next pointer of the current tail node to point to the newly created node which will be our tail after this 
// Step - 4 -> Return the head of the updated doubly Linked lIst in the function  call back 
class Node {
    public:
    // pehle sare data types jo use hone wale hai 
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

Node* convertarr(vector<int>arr){
    // array ke first element se head banao pehle 
    Node* head = new Node((arr[0]));
    // ek naya pointer banao prev naam ko jo piche point karega
    Node * prev = head;
    for(int i=0;i<arr.size();i++){
        // ek nayi temp node banao jiska data array se lo and set it's back pointer to the prev node 
        Node * temp = new Node(arr[i], nullptr, prev);
        // update the next pointer of the prev node to point to the new node 
        prev->next = temp;
        // move prev to the newly create node for the next iteration 
        prev = temp;
    }
    return head;

}

void print(Node * head){
    while(head != nullptr){
        cout << head->data << " ";
        head = head->next;
    }
}


Node* insertattail(Node* head, int k){
    // create a new node with data k
    Node* newNode = new Node(k);
 // agar LL khali hai to set head to the new node
    if(head == nullptr){
        return newNode;
    }
    Node* tail = head;
    // double LL ke end mai pahuch jao
    while(tail -> next != nullptr){
        tail = tail->next;
    }
    // connect the new node to the last node jo list mai hai
    tail->next = newNode;
    newNode-> back = tail;
    return head;
}
int main(){
    vector<int> arr = {12, 5, 8, 7, 4};
    Node* head = convertarr(arr);

    cout << "Doubly Linked List Initially: " << endl;
    print(head);


    cout << endl << "Doubly Linked List After Inserting at the tail with value 10: " << endl;
     // Insert a node with value 10 at the end
    head = insertattail(head, 10);
    print(head);

    return 0;
}