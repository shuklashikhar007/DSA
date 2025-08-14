// in this code we will learn how to traverse a linked list 
// basically how to find the length of a linked list by traversing it from starting to end.
#include<bits/stdc++.h>
using namespace std;
class Node {
    public :
    int data;
    Node* next;
    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};
int length(Node* head){
    Node * temp = head; // temp pointer holding address of head 
    int cnt = 0;
    while(temp != NULL){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}
int main(){
    vector<int> arr = {2,5,8,7};
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next= new Node(arr[3]);
    // this will print the length of the linked list
    cout << length(head) << endl;

    return 0;
}