#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};
class Solution{
    public:
    TreeNode * prev = nullptr;
    void flatten(TreeNode* root){
        if(root == nullptr) return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
};
void printpreorder(TreeNode * root){
    if(!root) return;
    cout << root->val << " ";
    printpreorder(root->left);
    printpreorder(root->right);
}
void printflat(TreeNode* root){
    if(!root) return;
    cout << root->val << " ";
    printflat(root->right);
}
int main(){
    // construct sample tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->left = new TreeNode(8);
    // create solution instance
    Solution sol;
    // print original tree preorder
    cout << "Binary Tree Preorder: ";
    printpreorder(root);
    cout << endl;
    // flatten the tree
    sol.flatten(root);
    // print flattened tree via right pointers
    cout << "Binary Tree After Flatten: ";
    printflat(root);
    cout << endl;
    return 0;
}