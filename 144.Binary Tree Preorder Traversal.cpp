/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        res.clear();
        stack<TreeNode *> temp;
        if(root == NULL) return res;
        //压栈
        temp.push(root);
        while(!temp.empty()){
            //获取栈顶元素
            TreeNode *node = temp.top();
            //栈顶元素出栈
            temp.pop();
            //将节点的值存入队列
            res.push_back(node->val);
            //这里要注意栈是FILO的存储结构,所以得先对右儿子进行压栈
            if(node->right != NULL){
                temp.push(node->right);
            }
            if(node->left != NULL){
                temp.push(node->left);
            }
        }
        return res;
    }
};