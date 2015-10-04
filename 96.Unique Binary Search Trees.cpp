/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/


class Solution {
public:
    int numTrees(int n) {
        //²Î¿¼£ºhttps://leetcode.com/discuss/24282/dp-solution-in-6-lines-with-explanation-f-i-n-g-i-1-g-n-i
        // F(i, n) = G(i-1) * G(n-i)
        vector<int> temp;
        temp.push_back(1);
        for(int i = 1; i <= n; ++i){
            int t = 0;
            for(int j = 0; j < i; ++j){
                t += temp[j] * temp[i - j -1];
            }
            temp.push_back(t);
        }
        return temp.back();
    }
};