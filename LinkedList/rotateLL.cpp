#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int num ;
    node* next;
    node(int a){
        num = a;
        next = NULL;
    }
};
void insertNode(node* &head, int val){
    // &head -> pass by reference beacuase we want the changes done here 
    // to the LL to reflect in the main() as well
    node* newnode = new node(val);
    if(head == NULL){
        head = newnode;
        return;
    }
    node* temp = head;
    while(temp->next != NULL ){
        temp = temp->next;
    }
    temp->next = newnode;
    return;
}
// function to rotate list by k times (rightside)
node* rotateright(node* head, int k){
    if(head == NULL || head->next == NULL){
        return head;
    }
    for(int i = 0; i < k ; i++){
        node* temp = head;
        // last ke piche wale pe traverse karo pehle 
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        node* end = temp->next;
        temp->next = NULL;
        end->next  = head;
        head = end;
    }

    return head;
}
void printList(node* head){
    while(head->next != NULL){
        cout << head->num << "->";
        head = head->next;
    }
    cout << head->num << endl;
    return;
} 
int main(){
    node* head = NULL;
    //inserting Node
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,4);
    insertNode(head,5);
    
    cout<<"Original list: ";
    printList(head);
    
    int k = 2;
    node* newHead = rotateright(head,k);//calling function for rotating right of 
   // the nodes by k times
    
    cout<<"After "<<k<<" iterations: ";
    printList(newHead);//list after rotating nodes
    return 0;   
}