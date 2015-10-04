/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        if(nums.size() == 1) return new TreeNode(nums[0]);
        int middle = nums.size() / 2;
        TreeNode * root = new TreeNode(nums[middle]);
        vector<int> leftNumber(nums.begin(), nums.begin()+middle);
        vector<int> rightNumber(nums.begin()+middle+1, nums.end());
        
        root -> left = sortedArrayToBST(leftNumber);
        root -> right = sortedArrayToBST(rightNumber);
        return root;
    }
};