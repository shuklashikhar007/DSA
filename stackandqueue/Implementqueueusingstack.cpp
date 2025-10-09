#include<bits/stdc++.h>
using namespace std;
struct Queue{
stack <int> input,output;

void push(int data){
    while(!input.empty()){
        output.push(input.top());
        input.pop();
    }
    cout << "The element pushed is: " << data << endl;
    input.push(data);

    while(!output.empty()){
        input.push(output.top());
        output.pop();
    }
}

int Pop(){
    if(input.empty()){
        cout << "Stack is empty" ;
    }

    int val = input.top();
    input.pop();
    return val;
}
int Top(){
    if(!input.empty()){
        cout << "Stack is empty" ;
        exit(0);
    }
    return input.top();
}

int size(){
    return input.size();
}
};
int main(){
    Queue q;
    q.push(3);
    q.push(4);
    cout << "The element popped is " << q.Pop() << endl;
    cout << "The size of the queue is " << q.size() << endl;
    return 0;
}
