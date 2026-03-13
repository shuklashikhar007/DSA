#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {};
};
class Solution{
    public:
    vector<int> inorder(TreeNode* root){
        stack<TreeNode* >st;
        TreeNode* node = root;
        vector<int> inorder;
        while (true)
        {
            if(node != NULL){
                st.push(node);
                node = node->left;
            }
            else{
                if(st.empty()){
                    break;
                }
                node = st.top();
                st.pop();
                inorder.push_back(node->data);
                node = node->right;
            }
        }
        return inorder;
    }
};
int main(){

    return 0;
}