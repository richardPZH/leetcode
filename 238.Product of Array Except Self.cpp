/*
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
*/


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int res = 1;
        int numOf0 = 0;
        for(int i = 0; i <nums.size(); ++i){
            if(nums[i] != 0){
                res *= nums[i];
            }else{
                numOf0++;
            }
        }
        
        for(int i = 0; i <nums.size(); ++i){
            if(nums[i] != 0){
                if(numOf0 ==0){
                    nums[i] = res / nums[i];
                }else{
                    nums[i] = 0;
                }
            }else{
                if(numOf0 == 1){
                    nums[i] = res;
                }else{
                    nums[i] = 0;
                }
            }
        }
        return nums;
    }
};