/*
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
*/

class Solution {
public:
    int titleToNumber(string s) {
        string arr[26] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
        int sum = 0;
        int index = 0;
        for(unsigned int i = 0; i < s.length(); i++){
            for(int j = 0; j < 26; j++){
                if(arr[j] == s.substr(i,1)){
                    index = j+1;
                }
            }
            sum += index*pow(26,s.length()-i-1);
        }
        return sum;
    }
};