/*Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        //思路：如果比i小的数字出现次数大于i,则重复值一定在1 ~ i之间
        //因为数字非0，所以这里l = 1，下面的for循环遍历则需从0开始；
        int l = 1,r = len - 1;
        int count = 0;
        int mid = 0;
        while(l < r){
            mid = l + (r - l)/2;
            for(int i = 0; i < len; ++i){
                if(nums[i] <= mid) count++;
            }
            if(count <= mid){
                l = mid + 1;
            }else{
                r = mid;
            }
            count = 0; //每次比较前，count需置0
        }
        return l;
    }
};