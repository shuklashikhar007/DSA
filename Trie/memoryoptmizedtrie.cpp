#include<bits/stdc++.h>
using namespace std;
// Ek memory optimized Trie template usefull In CP 
// this will use significantly less memory as compared to a array of pointers wali trie 
class Trie {

    struct Node {

        // nxt[i] stores index of next node
        // corresponding to character ('a' + i)

        int nxt[26];

        // how many words end here
        int endCount;

        // how many words pass through this node
        int prefixCount;

        Node() {

            // initialize all children as absent

            memset(nxt, -1, sizeof(nxt));

            endCount = 0;
            prefixCount = 0;
        }
    };

    // all trie nodes stored contiguously
    // node index acts like pointer

    vector<Node> trie;

public:

    Trie() {

        // create root node at index 0

        trie.push_back(Node());
    }

    // INSERT WORD

    void insert(string word) {

        int node = 0; // start from root

        for(char ch : word) {

            int c = ch - 'a';

            // if path does not exist
            // create new node

            if(trie[node].nxt[c] == -1) {

                trie[node].nxt[c] = trie.size();

                trie.push_back(Node());
            }

            // move to next node

            node = trie[node].nxt[c];

            // one more word passes through here

            trie[node].prefixCount++;
        }

        // word ends here

        trie[node].endCount++;
    }

    // SEARCH COMPLETE WORD

    bool search(string word) {

        int node = 0;

        for(char ch : word) {

            int c = ch - 'a';

            // path missing

            if(trie[node].nxt[c] == -1) {
                return false;
            }

            node = trie[node].nxt[c];
        }

        // word exists only if ending count > 0

        return trie[node].endCount > 0;
    }

    // CHECK PREFIX EXISTS

    bool startsWith(string prefix) {

        int node = 0;

        for(char ch : prefix) {

            int c = ch - 'a';

            if(trie[node].nxt[c] == -1) {
                return false;
            }

            node = trie[node].nxt[c];
        }

        return true;
    }

    // COUNT EXACT WORD

    int countWordsEqualTo(string word) {

        int node = 0;

        for(char ch : word) {

            int c = ch - 'a';

            if(trie[node].nxt[c] == -1) {
                return 0;
            }

            node = trie[node].nxt[c];
        }

        return trie[node].endCount;
    }

    // COUNT WORDS HAVING PREFIX

    int countWordsStartingWith(string prefix) {

        int node = 0;

        for(char ch : prefix) {

            int c = ch - 'a';

            if(trie[node].nxt[c] == -1) {
                return 0;
            }

            node = trie[node].nxt[c];
        }

        return trie[node].prefixCount;
    }

    // ERASE ONE OCCURRENCE OF WORD

    void erase(string word) {

        int node = 0;

        vector<int> path;

        for(char ch : word) {

            int c = ch - 'a';

            node = trie[node].nxt[c];

            path.push_back(node);
        }

        trie[node].endCount--;

        for(int x : path) {
            trie[x].prefixCount--;
        }
    }
};