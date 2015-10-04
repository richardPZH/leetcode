/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        int temp[26] = {0};
        int n = s.length();
        //统计出现的次数
        for(int i = 0; i < n; ++i){
            ++temp[s[i]-'a'];
            --temp[t[i]-'a'];
        }
        for(int i = 0; i < 26; i++){
            if(temp[i]){
                return false;  
            }
        }
        return true;
    }
};