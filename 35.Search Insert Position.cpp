/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 ¡ú 2
[1,3,5,6], 2 ¡ú 1
[1,3,5,6], 7 ¡ú 4
[1,3,5,6], 0 ¡ú 0
*/

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if(NULL == A || 0 == n)
            return 0;
        int minimum = 0, maximum = n-1, median;
        while(minimum <= maximum){
                median = minimum + (maximum - minimum) / 2;
                if(target < A[median]){
                    maximum = median - 1;
                }else if(target > A[median]){
                    minimum = median + 1;
                }else{
                    return median;
                }
        }
        return minimum;
    }
};