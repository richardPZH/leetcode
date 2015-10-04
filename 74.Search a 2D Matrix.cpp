/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = m * n - 1;
        while(left <= right){
            int middle = (right + left)/2;
            if(matrix[middle/n][middle%n] < target){
                left = middle + 1;
            }else if(matrix[middle/n][middle%n] > target){
                right = middle - 1;
            }else{
                return true; 
            }
        }
        return false;
    }
};