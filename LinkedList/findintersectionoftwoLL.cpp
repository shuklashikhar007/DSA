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


Node* reverseLL(Node* head){
    // temp to traveres the linked list
    Node* temp = head;
    // initialize pointer prev to NULL
    Node* prev = NULL;
    while(temp != NULL){
        // store next node is front to save the reference
        Node* front = temp->next;
        // reverse the direction of the 
        // current node's next pointer 
        // to point to 'prev'
        temp->next = prev;
        // move prev to temp agle iteration ke liye
        prev = temp;
        temp = front;
    }
    return prev;
}
Node* getkthnode(Node* temp, int k){
    // Decrement K until it reaches 
    // the desired 
    k -= 1;
    while(temp != NULL && k > 0){
        // Decrement k as temp progress
        k--;
        // Move to the next node 
        temp = temp -> next;
    }
    return temp;
}
Node* kReverse(Node* head, int k){
    // intialize a temp
    // temp node to traverse the list
    Node* temp = head;
    Node* prevlast = NULL;
    while(temp!= NULL){
        Node* kthNode = getkthnode(temp,k);
        // agar kth node null hai to not a complete group 
        // link the last node to the current node
        if(kthNode == NULL ){
            // if there was a prev group
            // to uss group ko link the last node to the current node
            if(prevlast){
                prevlast -> next = temp;
            }
            // exit the loop
            break;
        }
        // store the next node
        // after the kth node
        Node* nextNode = kthNode->next;

        // disconnect the kth node
        // prepare for reversal 
        kthNode -> next = NULL;
        reverseLL(temp);
        // adjust the head if traversal starts from the head
        if(temp == head){
            head = kthNode;
        }
        else{
            // link the last node of the previous 
            // group to the reversed group 
            prevlast -> next = kthNode;
        }


        // update the pointer to the last node of the previous group 
        prevlast = temp;
        temp = nextNode;
        return head;
    }
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
       // Create a linked list with
    // values 5, 4, 3, 7, 9 and 2
    Node* head = new Node(5);
    head->next = new Node(4);
    head->next->next = new Node(3);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->next = new Node(2);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLL(head);

    // Reverse the linked list
    head = kReverse(head, 4);
    // Print the reversed linked list
    cout << "Reversed Linked List: ";
    printLL(head);
    return 0;
}