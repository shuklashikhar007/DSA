#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    class Node {
    public:
        Node* nxt[26];
        int idx;
        int len;
        Node() {
            for(int i = 0; i < 26; i++) {
                nxt[i] = NULL;
            }
            idx = -1;
            len = 1e9;
        }
    };
    class Trie {
    public:
        Node* root;
        Trie() {
            root = new Node();
        }
        void update(Node* node, int wordLen, int index) {
            if(wordLen < node->len) {
                node->len = wordLen;
                node->idx = index;
            }
            else if(wordLen == node->len) {
                node->idx = min(node->idx, index);
            }
        }
        void insert(string &word, int index) {
            Node* node = root;
            update(node, word.size(), index); // ye wali call is done basically for wo wala case jab koi prefix match nahi hoga
            // us case mai hame shortest string length ka index return karege because jiska koi suffx nahi hai it still hgas " "
            // common with others that's why
            reverse(word.begin(), word.end());
            for(char ch : word) {
                int c = ch - 'a';
                if(node->nxt[c] == NULL) {
                    node->nxt[c] = new Node();
                }
                node = node->nxt[c];
                update(node, word.size(), index);
            }
        }
        int query(string &word) {
            Node* node = root;
            reverse(word.begin(), word.end());
            for(char ch : word){
                int c = ch - 'a';
                if(node->nxt[c] == NULL) { // ye bhi ek important egde case hai 
                // kyoki query mai esi string bhi ho sakti hai joi shayad puri kisi bhi container ki string ka prefix na ho 
                    break;
                }
                node = node->nxt[c];
            }
            return node->idx;
        }
    };
    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {
        Trie trie; // ye nahi bhulna hai to create a instance of a class object in main solution ]
        for(int i = 0; i < wordsContainer.size(); i++) {
            trie.insert(wordsContainer[i], i);
        }
        vector<int> ans;
        for(string &q : wordsQuery) {
            ans.push_back(trie.query(q));
        }
        return ans;
    }
};
int main(){

    return 0
}