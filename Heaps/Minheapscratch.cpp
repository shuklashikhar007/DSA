#include<bits/stdc++.h>
using namespace std;
// This can be very well understood after studying trees completely 
// before that will be hard to understand
// MIN heap how it is build and it's other functions 
class MinHeap {
    vector<int> h;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void heapifyUp(int i) {
        while (i > 0 && h[parent(i)] > h[i]) {
            swap(h[i], h[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int n = h.size();
        while (true) {
            int l = left(i), r = right(i);
            int smallest = i;

            if (l < n && h[l] < h[smallest]) smallest = l;
            if (r < n && h[r] < h[smallest]) smallest = r;

            if (smallest == i) break;
            swap(h[i], h[smallest]);
            i = smallest;
        }
    }

public:
    void push(int x) {
        h.push_back(x);
        heapifyUp(h.size() - 1);
    }

    void pop() {
        if (h.empty()) return;
        h[0] = h.back();
        h.pop_back();
        heapifyDown(0);
    }

    int top() {
        return h.empty() ? -1 : h[0];
    }

    int size() {
        return h.size();
    }

    bool empty() {
        return h.empty();
    }
};
// but we do not have time to write all this 
// so we will use simple STL inbuilt MINheap
int main(){
    priority_queue<int, vector<int>,greater<int>> minh; 
    // min heap with pairs
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    // syntax to create minheap
    return 0;
}