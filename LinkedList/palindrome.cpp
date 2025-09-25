#include<bits/stdc++.h>
using namespace std;
class Node{
public :
    int data;
    Node* next;

    Node(int data1,Node* next1){
        data = data1;
        next = next1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
    }

};
Node* reverseLL(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* newhead = reverseLL(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newhead;
}

void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
bool isPalindrome(Node* head){
    if(head == NULL || head->next == NULL){
        return true;
    }
    Node* slow = head;
    Node* fast = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        
        // Move slow pointer one step at a time
        slow = slow->next;  
        
        // Move fast pointer two steps at a time
        fast = fast->next->next;  
    }
    Node* newhead = reverseLL(slow->next);
    // pehle half ka pointer
    Node* first = head;
    // second half ka pointer
    Node* second = newhead;
    while(second != NULL){
        if(first->data != second->data){
            reverseLL(newhead); // agar reverse ke bad first hi match nahi kiya to reverse second half 
            // to restore it as before
            return false;
        }
        first = first->next;
        second = second->next;
    }

    reverseLL(newhead);
    return true;
}
int main(){
    // Create a linked list with
    // values 1, 5, 2, 5, and 1 (15251, a palindrome)
    Node* head = new Node(1);
    head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(1);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Check if the linked list is a palindrome
    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}