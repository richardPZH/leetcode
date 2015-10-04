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
            //��p������ӽڵ���ջ,ֱ������Ҷ�ӽڵ�
            while(p != NULL){
                temp.push(p);
                p = p->left;
            }
            if(!temp.empty()){
                //��ȡջ��Ԫ��
                p = temp.top();
                //��ջ
                temp.pop();
                //��������
                res.push_back(p->val);
                //ָ���Ҷ��ӽڵ�,����Ҷ��ӽڵ����,����������ڲ�whileѭ��������ջ����
                p = p->right;
            }
        }
        return res;
    }
};