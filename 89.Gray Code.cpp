/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*/

class Solution {
public:
    vector<int> grayCode(int n) {
        /*
        查看百度百科：
            １、1位格雷码有两个码字
            ２、(n+1)位格雷码中的前2n个码字等于n位格雷码的码字，按顺序书写，加前缀0
            ３、(n+1)位格雷码中的后2n个码字等于n位格雷码的码字，按逆序书写，加前缀1
            
            
            二进制码→格雷码（编码）：
            此方法从对应的n位二进制码字中直接得到n位格雷码码字，步骤如下：
            对n位二进制的码字，从右到左，以0到n-1编号
            如果二进制码字的第i位和i+1位相同，则对应的格雷码的第i位为0，否则为1（当i+1=n时，二进制码字的第n位被认为是0，即第n-1位不变）
            公式表示： Gi = Bi ^ Bi+1 （G：格雷码，B：二进制码）
            
            For example, trans binay '001' to gray code:
            tmp = 001 << 1
            then,
            bin 0 0 0 1
            tmp 0 0 1 0
            -xor------------
                0 0 1 1
            and the gray code is:
            0 0 1 1 >> 1 (ignore last bit) => 0 0 1

            以 n=３为例：
               binary Graycode(连续)  
            0   000     000
            1   001     001
            2   010     011
            3   011     010
            4   100     110
            5   101     111
            6   110     101
            7   111     100
            
            011(以3为例):
            
                0110
                0011
            ------------
                0101 >> 1　　（右移一位）
            ------------
                010
        */
        int N = 1 << n;
        int temp = 0;
        vector<int> result;
        for(int i = 0; i < N; ++i){
            temp = i << 1;
            result.push_back((temp ^ i) >> 1);
        }
        return result;
    }
};