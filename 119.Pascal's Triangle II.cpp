/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
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
        /*
        vector<vector<int>> res = {};
        for(int i = 0; i <= rowIndex; ++i){
            res.push_back(vector<int>(i + 1, 1));
            for(int j = 1; j < i; ++j){
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
            }
        }
        return res[rowIndex];
        */
        
        //�Դ�
        vector<int> res(rowIndex + 1,1);
        int i = 2;
        int temp1 = 1,temp2 = 0;
        while(i <= rowIndex){
            for(int j = 1; j < i; j++){
                temp2 = res[j];
                res[j] = temp1 + res[j];
                temp1 = temp2;
            }
            i++;
        }
        return res;
        
        /*��n�У�
        ��һ����Ϊ1,
        �ڶ�����Ϊ1��(n-1),
        ��������Ϊ1��(n-1)����n-2��/2,
        ���ĸ���Ϊ1��(n-1)����n-2��/2����n-3��/3
        ����������
        ���Կ��ǵݹ�ʵ��
        */
    }
};