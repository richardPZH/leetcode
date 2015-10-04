/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) return false;
		stack<char> temp;
		for(int i = 0; i < s.length(); i++){
			if(!temp.empty()){
				if(s[i] == temp.top()+1 || s[i] == temp.top()+2){
					temp.pop();
				}else{
					temp.push(s[i]);
				}
			}else{
				temp.push(s[i]);
			}
		}
		return temp.empty();
    }
};