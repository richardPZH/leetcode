/*
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*
        int len = nums.size();
        sort(nums.begin(),nums.end());
        if(nums[0] != nums[1]) return nums[0];
        if(nums[len - 1] != nums[len - 2]) return nums[len - 1];
        for(int i = 0; i < len - 1; ++i){
            if(nums[i] != nums[i - 1] && nums[i] != nums[i + 1]) return nums[i];
        }
        */
        
        /*
            位操作。不管非孤异元素重复多少次，这是通用做法。

            对于右数第i位，如果孤异元素该位为0，则该位为1的元素总数为3的整数倍。
            
            如果孤异元素该位为1，则该位为1的元素总数不为3的整数倍（也就是余1）。
            
            换句话说，如果第i位为1的元素总数不为3的整数倍，则孤异数的第i位为1，否则为0.
            
            （如果非孤异元素重复n次，则判断是否为n的整数倍）
            
        */
        int result = 0;
        int flag = 1;
        int len = nums.size();
        //当flag移动７次以后,达到int的可表示范围上限，while循环终止；
        //优化方案：可以先获取数组中最大值max，当flag >　2*max时终止while循环 
        while(flag){
            int count = 0;
            for(int i = 0; i < len; ++i){
                if(flag & nums[i]){
                    count++;
                }
            }
            if(count % 3 == 1){
                result |= flag;
            }
            flag <<= 1;
        }
        return result;
        
    }
};