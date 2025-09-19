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
Node* reverseLinkedList(Node* head){
    // this is the function to reverse the linked list using recursion 
    if(head == NULL || head->next == NULL){
        return head;
    } // this is the base case
    Node* newhead = reverseLinkedList(head->next);
    Node* front = head->next;
    // next node ko front mai store karlo to reverse the link later
    front->next = head;
    head->next = NULL;
    return newhead;
}
bool ispalindrome(Node * head){
    // check if the LL is empty
    if(head == NULL || head->next == NULL){
        // empty ya single size ll hamesa palindrome hi hongi
        return true;
    }
    Node* slow = head;
    Node* fast = head;

    while(fast -> next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    // reverse the second half of the linked list starting from the middle 
    // head of the linked list of the reverse LL from the middle
    Node* newHead = reverseLinkedList(slow->next);

    // pointer to the first half 
    Node* first = head;
    // pointer to the reversed second half
    Node* second = newHead;
    while(second != NULL){
        if(first->data != second->data){
            // reverse the second half 
            // back to it's original form ( taki ll modify na ho)
            return false;
        }
        // steps to move ahead in the LL
        first = first->next;
        second = second->next;
    }
    reverseLinkedList(newHead); // yaha tak agaye iska matlab palindrome hai ye
    // we reverse in the end so the original LL is not modified
    return true;
}
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
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
    if (ispalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}