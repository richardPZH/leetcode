/*
Given an integer, write a function to determine if it is a power of two.
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        //2的n次幂只有一个１
        return (n > 0) && (!(n&(n - 1)));
    }
};