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
            λ���������ܷǹ���Ԫ���ظ����ٴΣ�����ͨ��������

            ����������iλ���������Ԫ�ظ�λΪ0�����λΪ1��Ԫ������Ϊ3����������
            
            �������Ԫ�ظ�λΪ1�����λΪ1��Ԫ��������Ϊ3����������Ҳ������1����
            
            ���仰˵�������iλΪ1��Ԫ��������Ϊ3������������������ĵ�iλΪ1������Ϊ0.
            
            ������ǹ���Ԫ���ظ�n�Σ����ж��Ƿ�Ϊn����������
            
        */
        int result = 0;
        int flag = 1;
        int len = nums.size();
        //��flag�ƶ������Ժ�,�ﵽint�Ŀɱ�ʾ��Χ���ޣ�whileѭ����ֹ��
        //�Ż������������Ȼ�ȡ���������ֵmax����flag >��2*maxʱ��ֹwhileѭ�� 
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