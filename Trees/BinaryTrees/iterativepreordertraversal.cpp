#include<bits/stdc++.h>
using namespace std;
// tree  ka struct
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x) , left(nullptr), right(nullptr) {};
};
class Solution{
    public:
    vector<int> preorder(TreeNode * root){
        vector<int>preorder;
        if(root == nullptr){ // khali tree pas kardiya kisi ne function ke andar
            return preorder;
        }
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty())
        {
            root = st.top(); // cur node stack ke top par   
            st.pop();
            preorder.push_back(root->val);
            if(root->right != nullptr){
                st.push(root->right);
            }
            if(root->left != nullptr){
                st.push(root->left);
            }
        }
        return preorder;
    }
};
int main(){

    return 0;
}