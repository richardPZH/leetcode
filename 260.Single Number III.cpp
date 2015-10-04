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
            ���ȼ���nums�������������ֵ���򣬼�ΪAxorB

            ��flag = AxorB & (~(AxorB - 1))��flag�ĺ���ΪAxorB�ӵ�λ���λ����һ����0λ��������Ҳ����a,b��һ����ͬλ���ֵ�λ�ã�����Ӧ����
            
            ע��(~(AxorB - 1))��==  -AxorB
            
            �������AxorB = 6�������ƣ�0110������-AxorBΪ�������ƣ�1010��-6�Ĳ��룩��������̣�0110 - 1 = 0101, ��ȡ����1010��
            
            => flag = 2�������ƣ�0010��
            
            ���������������ʣ���ͬ0��1��
            
            ��ֻ����һ�ε��������ֱַ�Ϊa��b
            
            ��֪a & flag �� b & flag�Ľ��һ����ͬ
            
            ͨ�����ַ�ʽ�����ɽ�a��b��ֿ���
            
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