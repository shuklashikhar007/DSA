#include<bits/stdc++.h>
using namespace std;
/*
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode* curr = root;
    TreeNode* lastVisited = nullptr;
    while (curr != nullptr || !st.empty()) {
        if (curr != nullptr) {
            // Dive left
            st.push(curr);
            curr = curr->left;
        } else {
            TreeNode* peekNode = st.top();
            // If right child exists and hasn't been processed
            if (peekNode->right != nullptr && lastVisited != peekNode->right) {
                curr = peekNode->right;
            } else {
                // Right child is done (or null), safe to process root
                res.push_back(peekNode->val);
                lastVisited = st.top();
                st.pop();
            }
        }
    }
    return res;
}
*/
int main(){
    // postorder traversal ( left -> right -> root)
    return 0;
}