#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:

    class Node{
        public:

        Node* nxt[26];
        bool end;

        Node(){
            for(int i = 0; i < 26; i++){
                nxt[i] = NULL;
            }
            end = false;
        }

        bool has(char ch){
            return nxt[ch - 'a'] != NULL;
        }

        Node* get(char ch){
            return nxt[ch - 'a'];
        }

        void put(char c, Node* node){
            nxt[c - 'a'] = node;
        }
    };

    class Trie{
        public:

        Node* root;

        Trie(){
            root = new Node();
        }

        void insert(string word){

            Node* node = root;

            for(char c : word){

                if(!node->has(c)){
                    node->put(c, new Node());
                }

                node = node->get(c);
            }

            node->end = true;
        }

        bool checkpre(string word){

            Node* node = root;

            for(char c : word){

                node = node->get(c);

                // first check NULL
                if(node == NULL || node->end == false){
                    return false;
                }
            }

            return true;
        }
    };

    string longestString(vector<string> &words) {

        Trie trie;

        // insert all words
        for(string word : words){
            trie.insert(word); // word not words
        }

        string ans = "";

        for(string word : words){

            if(trie.checkpre(word)){
                if(word.length() > ans.length()){
                    ans = word;
                }

                else if(word.length() == ans.length() && word < ans){
                    ans = word;
                }
            }
        }

        if(ans == "") return "";

        return ans;
    }
};