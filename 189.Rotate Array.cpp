/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

[show hint]

Hint:
Could you do it in-place with O(1) extra space?
*/

class Solution {
public:
    void reverse(vector<int>& nums, int l, int r){
        int temp = 0;
        while(l < r){
            temp = nums[l];
            nums[l++] = nums[r];
            nums[r--] = temp;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        if(k > len) k = k % len;
        reverse(nums, 0, len - 1 - k);
        reverse(nums, len - k, len - 1);
        reverse(nums, 0, len - 1);
    }
};