/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* node){
        if(!node) return 0;
        return max(height(node->left),height(node->right)) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        if(!root)   return true;
        int left = height(root->left);
        int right = height(root->right);
        return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};