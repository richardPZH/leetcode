/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
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
    bool check(TreeNode* l, TreeNode* r){
        if(l == NULL && r == NULL) return true;
        if(l == NULL || r == NULL) return false;
        if(l->val != r->val) return false;
        return check(l->left,r->right) && check(l->right,r->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return check(root->left, root->right);
    }
};