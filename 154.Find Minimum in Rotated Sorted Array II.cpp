/*
Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        /*
        int len = nums.size();
        if(len == 0) return -1;
        for(int i = 1; i < len; ++i){
            //��һ�γ�����һ��Ԫ�رȵ�ǰԪ��Сʱ��ȡ����������Сֵ��Ĭ��ֻ rotated ��һ�Σ�
            if(nums[i] < nums[i - 1]) return nums[i];
        }
        return nums[0]; //���磺[1,2],�����ͨ�����д��뷵�ؽ����*/
        
        int len = nums.size();
        int l = 0;
        int r = len - 1;
        
        while(l < r){//good idea
            int mid = (l+r)/2;
            if(nums[mid] > nums[r]){
                l = mid + 1;
            }else if(nums[mid] < nums[r]){
                r = mid;//nums[mid]��������Сֵ
            }else{
                r--;
            }
        } 
        return nums[l];
    }
};