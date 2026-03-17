#include <bits/stdc++.h>
using namespace std;

// Structure to represent a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    // Constructor to initialize node with a value
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to count the number of nodes in a complete binary tree
    int countNodes(TreeNode* root) {
        // If tree is empty, return 0
        if (root == NULL) {
            return 0;
        }
        // Get height from left side
        int lh = findHeightLeft(root);
        // Get height from right side
        int rh = findHeightRight(root);
        // If heights are equal, it's a perfect binary tree
        if (lh == rh) {
            // Use formula: 2^h - 1
            return (1 << lh) - 1;
        }
        // Otherwise, recursively count left and right subtrees
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    // Helper function to find height of leftmost path
    int findHeightLeft(TreeNode* node) {
        int height = 0;
        while (node) {
            height++;
            node = node->left;
        }
        return height;
    }

    // Helper function to find height of rightmost path
    int findHeightRight(TreeNode* node) {
        int height = 0;
        while (node) {
            height++;
            node = node->right;
        }
        return height;
    }
};

int main() {
    // Create the binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    // Create solution object
    Solution sol;

    // Count total number of nodes
    int totalNodes = sol.countNodes(root);

    // Output the result
    cout << "Total number of nodes in the Complete Binary Tree: " << totalNodes << endl;

    return 0;
}
