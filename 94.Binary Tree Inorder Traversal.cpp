/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].
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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        res.clear();
        stack<TreeNode *> temp;
        TreeNode *p = root;
        while(p != NULL || !temp.empty()){
            //将p的左儿子节点入栈,直到最左叶子节点
            while(p != NULL){
                temp.push(p);
                p = p->left;
            }
            if(!temp.empty()){
                //获取栈顶元素
                p = temp.top();
                //出栈
                temp.pop();
                //存入结果集
                res.push_back(p->val);
                //指向右儿子节点,如果右儿子节点存在,则由上面的内层while循环进行入栈处理
                p = p->right;
            }
        }
        return res;
    }
};