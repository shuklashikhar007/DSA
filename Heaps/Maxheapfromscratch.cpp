#include<bits/stdc++.h>
using namespace std;
// implementation from scratch
class MaxHeap {
    vector<int> h;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void heapifyUp(int i) {
        while (i > 0 && h[parent(i)] < h[i]) {
            swap(h[i], h[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int n = h.size();
        while (true) {
            int l = left(i), r = right(i);
            int largest = i;

            if (l < n && h[l] > h[largest]) largest = l;
            if (r < n && h[r] > h[largest]) largest = r;

            if (largest == i) break;
            swap(h[i], h[largest]);
            i = largest;
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

    bool empty() {
        return h.empty();
    }
};

int main(){
    // implementation from STL
    priority_queue<int>maxh;
    // mac heap with pairs
    priority_queue<pair<int,int>> pq;
    // compares first element if tie 
    // will compare second element
    
    return 0;

}