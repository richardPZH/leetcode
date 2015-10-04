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
        //ѹջ
        temp.push(root);
        while(!temp.empty()){
            //��ȡջ��Ԫ��
            TreeNode *node = temp.top();
            //ջ��Ԫ�س�ջ
            temp.pop();
            //���ڵ��ֵ�������
            res.push_back(node->val);
            //����Ҫע��ջ��FILO�Ĵ洢�ṹ,���Ե��ȶ��Ҷ��ӽ���ѹջ
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