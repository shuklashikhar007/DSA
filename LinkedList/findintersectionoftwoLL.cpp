// Reverse linked list in groups ok K

#include<bits/stdc++.h>
using namespace std;
class ListNode{
    public:
        int data;
        ListNode* next;
    ListNode(int data1){
        data = data1;
        next = nullptr;
    }
    ListNode(int data1, ListNode* next1){
        data = data1;
        next = next1;
    }
};
class Solution{
    public:
    ListNode* reverseLL(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while(cur != nullptr){
            ListNode* front = cur->next;
            cur -> next= prev;
            prev = cur;
            cur = front;
        }
        return prev;
    }
    ListNode* getkthnode(ListNode* temp, int k){
        k--; // kyoki actually mai number of iteragtion k-1 hi hongi
        while (temp && k > 0)
        {
            temp = temp->next;
            k--;   
        }
    }
    ListNode* revkgroup(ListNode* head, int k){
    ListNode* temp = head; // cur group ka start pointer 
    ListNode* prevlast = nullptr;
    // last nodeof prev rev group 
    while (temp)
    {
        ListNode * kthnode = getkthnode(temp, k); 
        // curr group ki starting se kth node leke aao 
        // enough node hi nahi hai 
        if(kthnode == nullptr){
            if(prevlast){
                prevlast -> next = temp;
            }
            break;
        }
        // aggle group ki starting 
        ListNode* nextnode = kthnode->next;
        kthnode -> next = nullptr; // first disconnect to reverse safely
        ListNode* newhead = reverseLL(temp); // group ko reverse karo 
        if(temp == head){
            head = newhead;
        }
        else{
            prevlast -> next = newhead;
        }
        prevlast = temp;
        temp = nextnode;
    }
    return head;
}
};
int main(){

}