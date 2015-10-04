/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        /*
        int len = nums.size();
        for(int i = 0; i < len; ++i){
            if(nums[i] == target) return i;
        }
        return -1;
        */
        int len = nums.size();
        int l = 0;
        int r = len - 1;
        
        while(l <= r){
            int mid = (l+r)/2;
            if(nums[mid] == target) return mid;
            
            if(nums[l] <= nums[mid]){
                if(target >= nums[l] && target < nums[mid]){
                    r = mid - 1;
                }else{
                    l = mid + 1;
                }
            }
            
            if(nums[mid] <= nums[r]){
                if(target > nums[mid] && target <= nums[r]){
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }
        } 
        return -1;
    }
};