/*
Given an array of size n, find the majority element. The majority element is the element that appears more than n/2 times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int res = 0;
        for(int i =0; i < nums.size(); ++i){
            if(res == nums[i]){
                count++;
            }else{
                if(count > 0){
                    count--;
                }else{
                    res = nums[i];
                }
            }    
        }
        return res;
    }
};