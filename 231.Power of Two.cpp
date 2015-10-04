/*
Given an integer, write a function to determine if it is a power of two.
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        //2��n����ֻ��һ����
        return (n > 0) && (!(n&(n - 1)));
    }
};