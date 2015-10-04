/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

class Solution {
public:
    int climbStairs(int n) {
        int res = 0, temp = 0;
        int pre = 1;
        int current = 1;
        if(n ==0 || n ==1) return 1;
        for(int i =2; i <= n; i++){
            temp = pre + current;
            pre = current;
            current = temp;
        }
        return current;
    }
};