// Preorder traversal matlab 
// Root -> left -> right
#include<bits/stdc++.h>
using namespace std;
stack<int>st;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x){
        val = x;
        left = nullptr;
        right = nullptr;
    }
}
vector<int> preorder(TreeNode* root) {
    vector<int> res;
    if (!root) return res;
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        // Process the node immediately
        res.push_back(node->val);   
        // Push right first, so left is processed next
        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }
    return res;
}
int main(){
    TreeNode* root = new TreeNode(5);
    // in the call we process right first so that later left is processed first here 
    // taki root left order is preserved here
    vector<int>pre = preorder(root);
    return 0;
}