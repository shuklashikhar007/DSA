// is file mai sare fundamentals hai stack aur queue ke

#include<bits/stdc++.h>
using namespace std;
class Stack{
    int size;
    int * arr;
    int top;
    public:
        Stack(){ // functuion ek naya stack banane ke liye
            top = -1;
            size = 1000;
            arr = new int[size];
        }

        void push(int x){
            // function to push a value in a arr based stack
            top++;
            arr[top] = x;
        }

        int pop(){
            int x = arr[top]; // current top value
            top--;
            return x;
            // x return karke top ko piche le jao
        }
        int Top(){
            return arr[top]; // return the topmost element 
        }
        int Size(){
            return top + 1; // kyoki we initialized top with -1 to size top +1 hoga 
        }
};
int main(){
    Stack s;
    s.push(6);
    s.push(3);
    s.push(7);
    cout << "Top of the stack is before deleting any element " << s.Top() << endl;
    cout << "Size of stack before deleting any element " << s.Size() << endl;
    cout << "The element deleted is " << s.pop() << endl;
    cout << "Top of stack after deleting an element " << s.Top() << endl;
    return 0;
}