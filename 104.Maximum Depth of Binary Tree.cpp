/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
    int maxDepth(TreeNode *root) {
        int height = 0, rowCount = 1;
        if(root == NULL){
            return 0;
        }
        queue<TreeNode *> queue;
        queue.push(root);
        TreeNode *node;
        while(!queue.empty()){
            node = queue.front();
            queue.pop();
            rowCount --;
            
            if(node -> left){
                queue.push(node -> left);
            }
            
            if(node -> right){
                queue.push(node -> right);
            }
            
            if(rowCount == 0){
                height ++;
                rowCount = queue.size();
            }
        }
        return height;
    }
};