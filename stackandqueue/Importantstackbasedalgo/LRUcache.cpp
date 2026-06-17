#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int k, int v) {
        key = k;
        value = v;
        prev = nullptr;
        next = nullptr;
    }
};
class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;
    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    void insertAfterHead(Node* node) {
        Node* temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
    }

public:
    LRUCache(int cap) {
        capacity = cap;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1; // nahi mili key to 
        Node* node = mp[key]; // us key ka reference in O(1)
        deleteNode(node); // ye actually mai delete nahi hota hai here we basically remove it from the links and add it later on 
        insertAfterHead(node);
        return node->value;
    }
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->value = value; // update the value 
            deleteNode(node); // delete the stale entry 
            insertAfterHead(node); // move this to front as now this will be MRU
            return;
        }
        // New key
        Node* newNode = new Node(key, value);// naya node banaya 
        mp[key] = newNode; // usko map mai refer kiya 
        insertAfterHead(newNode); // insert after head as this is now MRU
        // Capacity exceeded
        if (mp.size() > capacity) { // agar cache ki capacity full hai and we want to insert a new entry 
            Node* lru = tail->prev; // delete the lru 
            mp.erase(lru->key); // delete se pehle remove from map 
            deleteNode(lru);
            delete lru;
        }
    }
};