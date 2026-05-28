#include<bits/stdc++.h>
using namespace std;
class Trie {
public:
    // ek alag node class banake node ke variable aur has, get, put banana hai sanse pehle
    class Node{ // Node struct variable 
        public:
        Node* nxt[26];
        bool end;
        Node(){
            for(int i=0;i<26;i++){
                nxt[i] = NULL;
            }
            end = false;
        }
        bool has(char ch){
            return nxt[ch-'a'] != NULL;
        }
        Node* get(char ch){ // Node* because it will return adress of the node of char ch
            return nxt[ch-'a'];
        }
        void put(char ch, Node* node){
            nxt[ch-'a'] = node;
        }
    };

    Node* rt; // Node custom variable wali root initialize kardi hai hamne
    Trie() {
        rt = new Node();
    }
    void insert(string word) {
        Node* cur = rt;
        for(char ch : word){
            if(!cur->has(ch)){
                cur->put(ch, new Node());
            }
            cur = cur->get(ch);
        }   
        cur->end = true;
    }

    
    bool search(string word) {
        Node* cur = rt;
        for(char ch : word){
            if(!cur->has(ch)){
                return false;
            }
            cur = cur->get(ch);
        }
        return cur->end;
    }
    
    bool startsWith(string prefix) {
        Node* cur = rt;
        for(char ch : prefix){
            if(!cur->has(ch)){
                return false;
            }
            cur = cur->get(ch);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */