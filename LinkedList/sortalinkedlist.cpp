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
Node* mergeTwoSortedLinkedLists(Node* list1, Node* list2){
    Node* dummynode = new Node(-1);
    Node* temp = dummynode;

    while(list1 != nullptr && list2 != nullptr){
        // compare elements of both lists and 
        // link the smaller node to the merged list
        if(list1->data <= list2->data){
            temp->next = list1; // link 1 pe value choti hai to link it 
            // and move the pointer ahead
            list1= list1->next;
        }
        else{ // matlab link2 pe value choti hai link1 vali value se 
            temp ->  next = list2;
            list2 = list2->next;
        }
        // abb jab check hogaya to move the temp pointer ahead
        // temp handle kar raha hai merged list ko 
        temp = temp->next;
    }
    // edge cases -> agar kisi list mai abhi bhi element bache hai to 
    // append them to the merged list in the end 
    if(list1 != nullptr){
        temp->next = list1;
    }
    else{
        temp->next = list2;
    }

    // return the merged list starting from the nect of the dummy node 
    return dummynode->next;
}
Node* findMiddle(Node* head){
    // agar list empty hai ya single node hai to head is the middle 
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    Node * slow = head;
    Node* fast = head->next;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
// imp -> this is the function to perform merge sort on a linked list

Node* sortLL(Node* head){
    // yahi base case hai if the list is empty or has only one node
    // it is already sorted return the head
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    Node* middle = findMiddle (head);
    // divide the list into two halves 
    Node* right = middle->next;
    middle->next = nullptr;
    Node* left = head;
    // function to sort the two parts 
    left = sortLL(left);
    right = sortLL(right);

    return mergeTwoSortedLinkedLists(left,right);
}
void printLinkedList(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){
    // Linked List: 3 2 5 4 1
    Node* head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(5);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(1);

    cout << "Original Linked List: ";
    printLinkedList(head);

    // Sort the linked list
    head = sortLL(head);

    cout << "Sorted Linked List: ";
    printLinkedList(head);
    return 0;
}