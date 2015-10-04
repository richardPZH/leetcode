/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> result = {};
        vector<int> temp;
        int rowCount = 1;
        queue<TreeNode *> queue;
        queue.push(root);
        TreeNode *node;
        
        while(!queue.empty()){
            node = queue.front();
            temp.push_back(node->val);
            queue.pop();
            rowCount --;
            
            if(node -> left) queue.push(node -> left);
            if(node -> right) queue.push(node -> right);
            
            if(rowCount == 0){
                result.push_back(temp);
                temp.clear();
                rowCount = queue.size();
            }
        }
        return result;
    }
};