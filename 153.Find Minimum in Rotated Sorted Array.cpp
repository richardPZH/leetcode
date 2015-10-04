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
            //��һ�γ�����һ��Ԫ�رȵ�ǰԪ��Сʱ��ȡ����������Сֵ��Ĭ��ֻ rotated ��һ�Σ�
            if(nums[i] < nums[i - 1]) return nums[i];
        }
        return nums[0]; //���磺[1,2],�����ͨ�����д��뷵�ؽ����*/
        
        int len = nums.size();
        int l = 0;
        int r = len - 1;
        
        while(nums[l] > nums[r]){//good idea
            int mid = (l+r)/2;
            if(nums[mid] > nums[r]){
                l = mid + 1;
            }else{
                r = mid;//nums[mid]��������Сֵ
            }
        } 
        return nums[l];
    }
};