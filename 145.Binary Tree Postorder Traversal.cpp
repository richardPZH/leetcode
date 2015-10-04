/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> res;
    void postorder(TreeNode *root) {
        if(root == NULL) return;
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        res.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode *root) {
        postorder(root);
        return res;
    }
};