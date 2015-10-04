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
            判断一个数独是否有效。有效的数独不强求有解。只要同一行、列、块里没有相同数字就行了。
            可以用二进制来表示，表位运算加速.
            可以依靠以下三个判断条件:
            横行的数字均含1-9，不重复
            纵列的数字均含1-9，不重复
            每个粗线宫内的数字均含1-9，不重复
            除1-9外可以存在空格子，空格子用 “.” 表示
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
                	cout << idx0 <<endl;    输出56
                	cout << idx1 <<endl;　　输出48
                	cout << idx2 <<endl;    输出8
                	cout << idx3 <<endl;    输出16
                	cout << idx4 <<endl;    输出256
                	注意后面两个的区别
                 */
                 int idx = 1 << (board[i][j] - '0');
                 //(i*3)/3 + j/3为粗线宫的索引.
                 // 按位与：　0101 & 1100 = 0100
                 if (row[i] & idx || col[j] & idx || block[i/3 * 3 + j / 3] & idx){
                     return false;
                 }
                 //按位或： 0101 | 1100 = 1101
                row[i] |= idx;
                col[j] |= idx;
                block[i/3 * 3 + j/3] |= idx;
             }
        }
        return true;
    }
    
    /*
    可以使用3个数组记录每行、每列、每个九宫格出现过的数字，然后遍历数独的数组即可。
    遇到数字时，检测对应行、对应列以及对应九宫格是否已经出现过该字，如果出现，返回false；
    否则，将对应行、对应列以及对应九宫格的该数字位置标记为1。
    
    时间复杂度：O(n2)
    空间复杂度：O(n2)
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