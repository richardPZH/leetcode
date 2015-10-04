/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        /*
        �ٶȰٿƣ������������ϵ����ܵ��Ƕ���ʽ�˷�չ��ʽ��ϵ�����ɣ�������ʽ����
            ������ǣ�
                           1
                         1   1   
                       1   2   1   
                     1   3   3   1   
                   1   4   6   4   1   
                 1   5   10  10  5   1   
               1   6   15  20  15  6   1   
             1   7   21  35  35  21  7   1   
           1   8   28  56  70  56  28  8   1   
        */
        vector<vector<int>> res = {};
        for(int i = 0; i < numRows; ++i){
            res.push_back(vector<int>(i + 1, 1));
            for(int j = 1; j < i; ++j){
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
            }
        }
        return res;
    }
};