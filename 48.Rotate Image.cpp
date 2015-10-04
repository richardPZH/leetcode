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
            �������Ÿ��Խ��߷�תһ�Σ�������ˮƽ���߷�תһ�Σ�
            ����
            ������ˮƽ���߷�ת�����������Խ��߷�ת��
        
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