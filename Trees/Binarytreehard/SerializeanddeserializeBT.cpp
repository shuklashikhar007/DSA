#include<bits/stdc++.h>
using namespace std;
// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
class Solution{
public:
    string serialize(Node* root){
        if(!root) return "";
        string s = "";
        queue<Node*>q;
        q.push(root);
        while (!q.empty())
        {
            Node* curnode = q.front();
            q.pop();
            if(curnode == NULL) s.append("#,");
            else s.append(to_string(curnode->data) + ',');
            if(curnode != NULL){
                q.push(curnode->left);
                q.push(curnode->right);
            }
        }
        cout << s ;
        return s;
    }
    Node* deserialize(string data){
        if(data.size() == 0) return NULL;
        stringstream s(data);
        string str;
        getline(s, str,',');
        Node* root = new Node(stoi(str));
        queue<Node*>q;
        q.push(root);
        // puri 
        while (!q.empty())
        {
            Node* node = q.front();
            q.pop();
            getline(s,str,',');
            if(str == "#"){
                node->left = NULL;
            }
            else{
                Node* leftnode = new Node(stoi(str));
                node->left = leftnode;
                q.push(leftnode);
            }
            getline(s,str,',');
            if(str == "#"){
                node->right = NULL;
            }
            else{
                Node* rightnode = new Node(stoi(str));
                node->right = rightnode;
                q.push(rightnode);
            }
        }
        return root;
    }
};