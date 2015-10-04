/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
    int minDepth(TreeNode* root) {
        int height = 0, rowCount = 1;
        if(root == NULL){
            return 0;
        }
        queue<TreeNode *> queue;
        queue.push(root);
        while(!queue.empty()){
            TreeNode *node = queue.front();
            queue.pop();
            rowCount --;
            
            if(node -> left){
                queue.push(node -> left);
            }
            
            if(node -> right){
                queue.push(node -> right);
            }
            
            //类似于这个题：https://leetcode.com/problems/maximum-depth-of-binary-tree/
            if(node->left == NULL && node->right == NULL){
                height++;
                break;
            }
            
            if(rowCount == 0){
                height ++;
                rowCount = queue.size();
            }
        }
        return height;
    }
};