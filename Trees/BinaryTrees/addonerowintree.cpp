#include<bits/stdc++.h>
using namespace std;

  struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
  right(right) {}
  };
 
class Solution {
public:
    // case 2:
    TreeNode* add(TreeNode* root, int val, int depth, int curr) {
        if (root == NULL)
            return NULL;
        if (curr == depth - 1) {
            // move current roots to temporary nodes
            TreeNode* leftTemp = root->left;
            TreeNode* rightTemp = root->right;
            // assign the givens values to the (root -> left/right)
            root->left = new TreeNode(val);
            root->right = new TreeNode(val);
            // now attach the old nodes onto the newly enters roots of left and
            // right
            root->left->left = leftTemp;
            root->right->right = rightTemp;
            return root;
        }
        root->left = add(root->left, val, depth, curr + 1);
        root->right = add(root->right, val, depth, curr + 1);
        return root;
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        // case 1 : if depth is 1, create new node and assign the given (val) to
        // it and move the current root to left of it.
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            (newRoot->left) = root;
            return newRoot;
        }
        int curr = 0;
        return add(root, val, depth, 1);
    }
};
int main(){

    return 0;
}