// tortoise and hare algo to find middle of a linked list
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
Node* findmiddle(Node* head){
    Node* slow = head;
    Node* fast = head; // fast ko head pe intialize karne pe middle mai second middle ayega in case of even no of node wali LL
    // AGAR FIRST middle chaiye to initialize like Node* fast = head->next;
    while(fast != NULL &&fast->next != NULL){
        slow= slow->next;
        fast = fast->next->next;
    }
    return slow;
}
int main(){
    vector<int>arr = {1,2,3,4,5,6};
    Node* head = makeLL(arr);
    Node* middle = findmiddle(head);
    cout << middle->data << endl;
    return 0;
}