#include<bits/stdc++.h>
using namespace std;
class PriorityQueue {
    vector<pair<int,int>> h; // {priority, value}

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void heapifyUp(int i) {
        while (i > 0 && h[parent(i)].first > h[i].first) {
            swap(h[i], h[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int n = h.size();
        while (true) {
            int l = left(i), r = right(i);
            int smallest = i;

            if (l < n && h[l].first < h[smallest].first) smallest = l;
            if (r < n && h[r].first < h[smallest].first) smallest = r;

            if (smallest == i) break;
            swap(h[i], h[smallest]);
            i = smallest;
        }
    }

public:
    void push(int priority, int value) {
        h.push_back({priority, value});
        heapifyUp(h.size() - 1);
    }

    void pop() {
        if (h.empty()) return;
        h[0] = h.back();
        h.pop_back();
        heapifyDown(0);
    }

    pair<int,int> top() {
        return h.empty() ? make_pair(-1,-1) : h[0];
    }
};
// this is how to implement from basics (or scratch)  using Binary Trees

int main(){
    // how to implement using STL
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    

    return 0;
}