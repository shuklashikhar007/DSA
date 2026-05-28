#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node* links[26];
    int cntends = 0;
    int cntpre = 0;
    bool containskey(char ch){
        return links[ch-'a'] != NULL;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch, Node* node){
        links[ch-'a']= node;
    }
    // function to increase the cnt of words that end at this node
    void increaseEnd(){
        cntends++;
    }
    // function to incre the cnt of words that have this node as a prefix
    void increasepre(){
        cntpre++;
    }
    void decreasepre(){
        cntpre--;
    }
    void deleteend(){
        cntends--;
    }
};
class Trie{
    private:
    Node* root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(string word){
        Node* node = root;
        for(char c : word){
            if(!node->containskey(c)){
                node->put(c, new Node());
            }
            node = node->get(c);
            // is node ka prefix cnt bada do -> basically the number of words having this node in it 
            node->increasepre();
        }
        node->increaseEnd(); // is node pe ek word end ho raha hai to increase the count of number of words
        // ending at this node
    }
    int cntwordsequalto(string word){
        Node* node = root;
        for(char c : word){
            if(!node->containskey(c)){
                return 0; // char hi nahi mila matlab ye word hi pura nahi hai trie mai
            }
            else{
                node=node->get(c); // keep moving forward
            }
        }
        return node->cntends; // end mai ake return the number of word ending at the last char 
    }
    int cntwordstartwith(string word){
        Node* node = root;
        for(char c : word){
            if(node->containskey(c)){
                node = node->get(c); 
                // mil gya to agge badho 
            }
            else{ // word ka char hi nahi mila to return 0
                return 0;
            }
        } // prefix cnt is basically how many words contain this node 
        return node->cntpre;
    }
    void erase(string word){
        Node* node = root;
        for(char c: word){
            if(node->containskey(c)){
                node = node->get(c);
                node->decreasepre();
                // decrease the number of words cnt that contain this node
            }
            else{
                return; // ye word yaha to hat gya already ya to esa
                // word hai input mai jo trie mai hai hi nahi
            }
        }
        node->deleteend(); // delete the end -> basically decrease the number of words that end with the last node
    }
};
int main(){

    return 0;
}