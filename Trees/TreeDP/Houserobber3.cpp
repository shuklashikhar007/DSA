#include<bits/stdc++.h>
using namespace std;
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
    pair<int,int>solve(TreeNode* root){
        if(!root) return {0,0};
        // post order traversal pehle children fir parents
        pair<int,int>val1 = solve(root->left);
        pair<int,int>val2 = solve(root->right);
        int take = root->val + val1.second + val2.second;
        int skip = val1.first + val2.first;
        return {max(take,skip),skip};
    }
    int rob(TreeNode* root) {
        pair<int,int>ans = solve(root);
        return ans.first;
    }
};
int main(){

    return 0;
}