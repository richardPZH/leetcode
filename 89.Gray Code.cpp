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
        �鿴�ٶȰٿƣ�
            ����1λ����������������
            ����(n+1)λ�������е�ǰ2n�����ֵ���nλ����������֣���˳����д����ǰ׺0
            ����(n+1)λ�������еĺ�2n�����ֵ���nλ����������֣���������д����ǰ׺1
            
            
            ��������������루���룩��
            �˷����Ӷ�Ӧ��nλ������������ֱ�ӵõ�nλ���������֣��������£�
            ��nλ�����Ƶ����֣����ҵ�����0��n-1���
            ������������ֵĵ�iλ��i+1λ��ͬ�����Ӧ�ĸ�����ĵ�iλΪ0������Ϊ1����i+1=nʱ�����������ֵĵ�nλ����Ϊ��0������n-1λ���䣩
            ��ʽ��ʾ�� Gi = Bi ^ Bi+1 ��G�������룬B���������룩
            
            For example, trans binay '001' to gray code:
            tmp = 001 << 1
            then,
            bin 0 0 0 1
            tmp 0 0 1 0
            -xor------------
                0 0 1 1
            and the gray code is:
            0 0 1 1 >> 1 (ignore last bit) => 0 0 1

            �� n=��Ϊ����
               binary Graycode(����)  
            0   000     000
            1   001     001
            2   010     011
            3   011     010
            4   100     110
            5   101     111
            6   110     101
            7   111     100
            
            011(��3Ϊ��):
            
                0110
                0011
            ------------
                0101 >> 1����������һλ��
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