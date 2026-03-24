#include<bits/stdc++.h>
using namespace std;
int main(){}

struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return NULL;
        }
        if(root->val == key){ // edge case agar root hi delete karne wali node hai to
            return helper(root);
        }
        TreeNode* dummy = root;
        while(root != NULL){
            if(root->val > key){
                if(root->left != NULL && root->left->val == key){
                    root->left = helper(root->left);
                    break;
                }
                else{
                    root = root->left;
                }
            }
            else{
                if(root->right != NULL && root->right->val == key){
                    root->right = helper(root->right);
                    break;
                }
                else{
                    root = root->right;
                }
            }
        }
        return dummy;
    }
    TreeNode* helper(TreeNode* root){
        if(root->left == NULL){ // left part hai nahi to return right part
            return root->right;
        }
        if(root->right == NULL){ // right part hai nahi to return left part
            return root->left;
        }
        TreeNode* rchild = root->right;
        TreeNode* lastr = findlast(root->left);
        lastr->right = rchild;
        return root->left; // jo pass hua tha uske left ke rightmost se jo pass hua tha uska right connect karke return 
    }
    TreeNode* findlast(TreeNode* root){
        if(root->right == NULL){
            return root;
        }
        return findlast(root->right);
    }
    
};