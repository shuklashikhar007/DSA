#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution{
    public:
    void postorder(TreeNode* root, vector<int>&result){
        if(!root) return;
        postorder(root->left, result);
        postorder(root->right, result);
        result.push_back(root->val);
    }
};
int main(){
    // Build tree:    1
    //              /   \
    //             2     3
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution sol;
    vector<int> result;
    sol.postorder(root, result);
    for (int val : result) cout << val << " ";
    return 0;
}