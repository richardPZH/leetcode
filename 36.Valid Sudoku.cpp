/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
*/


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        /*
            �ж�һ�������Ƿ���Ч����Ч��������ǿ���н⡣ֻҪͬһ�С��С�����û����ͬ���־����ˡ�
            �����ö���������ʾ����λ�������.
            �����������������ж�����:
            ���е����־���1-9�����ظ�
            ���е����־���1-9�����ظ�
            ÿ�����߹��ڵ����־���1-9�����ظ�
            ��1-9����Դ��ڿո��ӣ��ո����� ��.�� ��ʾ
        */
        vector<short> row(9,0);
        vector<short> col(9,0);
        vector<short> block(9,0);
        for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++) {
             if (board[i][j] != '.') {
                 /*
                    int idx0 = ('8');
                	int idx1 = ('0');
                	int idx2 = ('8' - '0');
                	int idx3 = 8 << 1;
                	int idx4 = 1 << ('8' - '0');
                	cout << idx0 <<endl;    ���56
                	cout << idx1 <<endl;�������48
                	cout << idx2 <<endl;    ���8
                	cout << idx3 <<endl;    ���16
                	cout << idx4 <<endl;    ���256
                	ע���������������
                 */
                 int idx = 1 << (board[i][j] - '0');
                 //(i*3)/3 + j/3Ϊ���߹�������.
                 // ��λ�룺��0101 & 1100 = 0100
                 if (row[i] & idx || col[j] & idx || block[i/3 * 3 + j / 3] & idx){
                     return false;
                 }
                 //��λ�� 0101 | 1100 = 1101
                row[i] |= idx;
                col[j] |= idx;
                block[i/3 * 3 + j/3] |= idx;
             }
        }
        return true;
    }
    
    /*
    ����ʹ��3�������¼ÿ�С�ÿ�С�ÿ���Ź�����ֹ������֣�Ȼ��������������鼴�ɡ�
    ��������ʱ������Ӧ�С���Ӧ���Լ���Ӧ�Ź����Ƿ��Ѿ����ֹ����֣�������֣�����false��
    ���򣬽���Ӧ�С���Ӧ���Լ���Ӧ�Ź���ĸ�����λ�ñ��Ϊ1��
    
    ʱ�临�Ӷȣ�O(n2)
    �ռ临�Ӷȣ�O(n2)
    */
    bool isValidSudoku1(vector<vector<char>>& board) {
        int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};
         
        for(int i = 0; i < board.size(); ++ i)
             for(int j = 0; j < board[i].size(); ++ j)
                 if(board[i][j] != '.')
                 {
                     int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                     if(used1[i][num] || used2[j][num] || used3[k][num])
                         return false;
                     used1[i][num] = used2[j][num] = used3[k][num] = 1;
                 }
         
         return true;
    }
};