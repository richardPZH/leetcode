/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        /*int len = nums.size();
        for(int i = 0; i < len; ++i){
            if(nums[i] == target) return true;
        }
        return false;*/
        
        int len = nums.size();
        int l = 0;
        int r = len - 1;
        int mid = 0;
        
        while(l <= r){
            mid = (l+r)/2;
            if(nums[mid] == target) return true;
            
            if(nums[l] == nums[mid] && nums[mid] == nums[r]){
                l++;
                r--;
            }else if(nums[l] <= nums[mid]){
                if(target >= nums[l] && target < nums[mid]){
                    r = mid - 1;
                }else{
                    l = mid + 1;
                }
            }else{
                if(target > nums[mid] && target <= nums[r]){
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }
        } 
        return false;
    }
};