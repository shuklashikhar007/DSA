#include<bits/stdc++.h>
using namespace std;
int main(){
    
}
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
    using ll = long long;
    bool isvalid(TreeNode* root, ll min, ll max){
        if(root == NULL) return true;
        if(root->val >= max || root->val <= min){
            return false;
        } 
        return isvalid(root->left, min, root->val) && isvalid(root->right, root->val , max);
    }
    bool isValidBST(TreeNode* root) {
        return isvalid(root, LLONG_MIN, LLONG_MAX);
    }
};