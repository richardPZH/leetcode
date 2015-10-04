/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        /*
            首先沿着副对角线翻转一次，再沿着水平中线翻转一次；
            或者
            先沿着水平中线翻转，再沿着主对角线翻转；
        
        */
        int n = matrix.size();
        int temp = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < i; ++j){
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for(int i = 0; i < n; ++i){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};