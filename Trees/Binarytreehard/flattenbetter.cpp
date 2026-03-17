#include <bits/stdc++.h>
using namespace std;

// define tree node structure
struct TreeNode {
    // value field
    int val;
    // left child pointer
    TreeNode *left;
    // right child pointer
    TreeNode *right;
    // constructor
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// solution class
class Solution {
public:
    // keep same field as original (unused in iterative version)
    TreeNode* prev = nullptr;

    // flatten binary tree to right-skewed linked list (iterative)
    void flatten(TreeNode* root) {
        // handle empty tree
        if (root == nullptr) return;
        // create stack for DFS
        stack<TreeNode*> st;
        // push root to start traversal
        st.push(root);
        // process while stack has nodes
        while (!st.empty()) {
            // take top node
            TreeNode* cur = st.top();
            // pop it
            st.pop();
            // push right child first (so left is processed first)
            if (cur->right != nullptr) st.push(cur->right);
            // push left child next
            if (cur->left != nullptr) st.push(cur->left);
            // if stack not empty, link current's right to next node
            if (!st.empty()) cur->right = st.top();
            // nullify left to form right-only chain
            cur->left = nullptr;
        }
    }
};

// print preorder traversal
void printPreorder(TreeNode* root) {
    // stop at null
    if (!root) return;
    // print current node
    cout << root->val << " ";
    // recurse left
    printPreorder(root->left);
    // recurse right
    printPreorder(root->right);
}

// print along right pointers
void printFlattenTree(TreeNode* root) {
    // stop at null
    if (!root) return;
    // print current node
    cout << root->val << " ";
    // move right
    printFlattenTree(root->right);
}

// program entry
int main() {
    // build sample tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->left = new TreeNode(8);

    // create solver
    Solution sol;

    // show preorder before flatten
    cout << "Binary Tree Preorder: ";
    printPreorder(root);
    cout << endl;

    // perform flatten
    sol.flatten(root);

    // show right-chain after flatten
    cout << "Binary Tree After Flatten: ";
    printFlattenTree(root);
    cout << endl;

    // done
    return 0;
}