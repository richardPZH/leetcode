/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        /*
        int len = nums.size();
        if(len == 0) return -1;
        for(int i = 1; i < len; ++i){
            //第一次出现下一个元素比当前元素小时即取得了数组最小值：默认只 rotated 了一次？
            if(nums[i] < nums[i - 1]) return nums[i];
        }
        return nums[0]; //比如：[1,2],则必须通过此行代码返回结果；*/
        
        int len = nums.size();
        int l = 0;
        int r = len - 1;
        
        while(nums[l] > nums[r]){//good idea
            int mid = (l+r)/2;
            if(nums[mid] > nums[r]){
                l = mid + 1;
            }else{
                r = mid;//nums[mid]可能是最小值
            }
        } 
        return nums[l];
    }
};