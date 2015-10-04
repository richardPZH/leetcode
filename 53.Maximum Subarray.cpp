/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [?2,1,?3,4,?1,2,1,?5,4],
the contiguous subarray [4,?1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //�҂����Ƚ���һ���cԭ����A�L����ͬ�Ĕ���dp��dp�е�ÿһ��ֵdp[i]��ʾ��λ��i��K�c���Ӕ��е����͡�Induction case�� �����ǰ��һ��λ�Þ�Y�����Ӕ��к͞���������dp[i-1]>0,���Ndp[i]=dp[i-1]+A[i]����tdp[i]=A[i]�����Ndp[n]�����҂���Ҫ��ԓ���е�����B�m�Ӕ���֮��
        vector<int> dp = nums;
        int max = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            if(dp[i - 1] > 0){
                dp[i] = dp[i - 1] + nums[i];
            }
            max = max > dp[i] ? max : dp[i];
        }
        return max;
    }
};