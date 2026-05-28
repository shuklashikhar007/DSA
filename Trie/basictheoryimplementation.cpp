#include <bits/stdc++.h> // includes almost all standard C++ libraries
using namespace std;    // so we can use cout, string, etc. directly
// each node of trie
class Node {
public:
    Node* nxt[26];
    // array of pointers
    // nxt[0] -> child for 'a'
    // nxt[1] -> child for 'b'
    // ...
    // nxt[25] -> child for 'z'
    bool end;
    // true if a word ends at this node
    int cnt;
    // stores how many words pass through this node
    // useful for prefix count queries
    // constructor
    Node() {
        // initially all children are NULL
        // meaning no character path exists yet
        for (int i = 0; i < 26; i++) {
            nxt[i] = NULL;
        }
        end = false;
        // initially no word ends here
        cnt = 0;
        // initially no word passes through node
    }
    // checks whether child for character exists
    bool has(char ch) {
        // convert character into index
        // 'a' -> 0
        // 'b' -> 1
        // etc.
        return nxt[ch - 'a'] != NULL;
    }
    // returns pointer of next node
    Node* get(char ch) {

        return nxt[ch - 'a'];
    }
    // creates connection with next node
    void put(char ch, Node* node) {
        nxt[ch - 'a'] = node;
    }
};
// Trie class
class Trie {
public:
    Node* rt;
    // root node of trie
    // constructor
    Trie() {
        // create empty root node
        rt = new Node();
    }
    // inserts a word into trie
    void insert(string s) {
        // start from root
        Node* cur = rt;
        // traverse every character
        for (char ch : s) {
            // if pathdoes not exist
            if (!cur->has(ch)) {
                // create new node
                cur->put(ch, new Node());
            }
            // move to next node
            cur = cur->get(ch);
            // one more word passes through this node
            cur->cnt++;
        }
        // mark end of complete word
        cur->end = true;
    }
    // checks if exact word exists
    bool search(string s) {
        // start from root
        Node* cur = rt;
        // traverse all characters
        for (char ch : s) {
            // if path missing
            // word does not exist
            if (!cur->has(ch)) {
                return false;
            }
            // move ahead
            cur = cur->get(ch);
        }
        // return true only if complete word ends here
        // prevents prefixes from being treated as words
        return cur->end;
    }
    // checks whether any word starts with prefix
    bool startsWith(string s) {
        // start from root
        Node* cur = rt;
        // traverse prefix
        for (char ch : s) {
            // if path missing
            // prefix not present
            if (!cur->has(ch)) {
                return false;
            }
            // move to next node
            cur = cur->get(ch);
        }
        // all prefix characters found
        return true;
    }
    // returns number of words having given prefix
    int prefCnt(string s) {
        // start from root
        Node* cur = rt;
        // traverse prefix
        for (char ch : s) {
            // if prefix path missing
            if (!cur->has(ch)) {

                return 0;
            }
            // move ahead
            cur = cur->get(ch);
        }
        // cnt stores how many words pass through
        // this node = words having this prefix
        return cur->cnt;
    }
};

int main() {

    Trie t;
    // create trie object

    // insert words
    t.insert("apple");
    t.insert("app");
    t.insert("ape");
    t.insert("bat");

    cout << boolalpha;
    // prints true/false instead of 1/0

    // exact word search
    cout << t.search("apple") << endl;
    // true

    cout << t.search("app") << endl;
    // true

    cout << t.search("appl") << endl;
    // false because full word not inserted

    // prefix checks
    cout << t.startsWith("ap") << endl;
    // true

    cout << t.startsWith("ba") << endl;
    // true

    cout << t.startsWith("cat") << endl;
    // false

    // count words with prefix "ap"
    // apple, app, ape
    // answer = 3
    cout << t.prefCnt("ap") << endl;

    return 0;
    // program ends
}