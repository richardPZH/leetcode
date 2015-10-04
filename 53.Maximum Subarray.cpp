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
        //我們首先建立一個與原數列A長度相同的數列dp，dp中的每一個值dp[i]表示以位置i為終點的子數列的最大和。Induction case： 如果以前面一個位置為結束的子數列和為正數，既dp[i-1]>0,那麼dp[i]=dp[i-1]+A[i]；否則dp[i]=A[i]。那麼dp[n]就是我們想要的該數列的最大連續子數列之和
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