/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        int j = 1;
        int new_len = 1;
        int current = nums[0];
        while(j < len){
            if(nums[j] == current){
                j++;
            }else{
                current = nums[j];
                nums[new_len] = nums[j];
                new_len++;
            }
        }
        return new_len;
    }
};