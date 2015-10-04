/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        /*
            首先计算nums数组中所有数字的异或，记为AxorB

            令flag = AxorB & (~(AxorB - 1))，flag的含义为AxorB从低位向高位，第一个非0位（即１：也就是a,b第一个不同位出现的位置）所对应的数
            
            注：(~(AxorB - 1))　==  -AxorB
            
            例如假设AxorB = 6（二进制：0110），则-AxorB为（二进制：1010（-6的补码），计算过程：0110 - 1 = 0101, 再取反得1010）
            
            => flag = 2（二进制：0010）
            
            根据异或运算的性质，“同0异1”
            
            记只出现一次的两个数字分别为a与b
            
            可知a & flag 与 b & flag的结果一定不同
            
            通过这种方式，即可将a与b拆分开来
            
        */
        int AxorB = 0;
        int len = nums.size();
        int flag = 0;
        int A = 0, B = 0;
        
        for(int i = 0; i < len; ++i){
            AxorB ^= nums[i];
        }
        
        flag = AxorB & (~(AxorB - 1));
        
        for(int j = 0; j < len; ++j){
            if((flag & nums[j]) == 0){
                A ^= nums[j];
            }else{
                B ^= nums[j];                
            }
        }
        return vector<int>({A,B});
    }
};