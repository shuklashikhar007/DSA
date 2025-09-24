// this code will only remove duplicates and maintain array with unique elements only 
// to completely remove duplicates elements we use dummy node approach 
#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
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
Node* convertarr2DLL(vector<int>arr){
// function to make a array a 2DLL
    Node* head = new Node(arr[0]);
    Node* prev = head;  
    int n = arr.size();
    for(int i=1 ; i < n ; i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}
Node* removeduplicates(Node* head){
    Node* temp = head;
    while(temp != NULL && temp->next != NULL){
        Node* nextnode = temp->next;
        while(nextnode != NULL && nextnode->data == temp->data){
            nextnode = nextnode->next; // keep skipping the nodes having duplicates 
        }
        temp->next = nextnode; // front link
        if(nextnode != NULL){
            nextnode -> back = temp; // backlink
        } 
        temp = nextnode;
    }
    return head;
}
void print(Node* head){
    while(head != nullptr){
        cout << head->data << " " ;
        head = head->next;
    }
}

int main(){
    vector<int>arr = {1,1,1,2,3,3,4};
    Node* head = convertarr2DLL(arr);
    print(head);
    Node* head2 = removeduplicates(head);
    cout << endl;
    print(head2);
    return 0;
}