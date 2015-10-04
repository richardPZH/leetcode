/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 0) return;
        int numOf0 = 0;
        int numOf1 = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == 0){
                numOf0++;
            }else{ 
                nums[numOf1] = nums[i];
                numOf1++;
            }
        }
        
        for(int i = numOf1; i < nums.size(); ++i){
            nums[i] = 0;
        }
    }
};