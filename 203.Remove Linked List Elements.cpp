/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return NULL;
		if(!val) return head;
		ListNode *new_head = new ListNode(0);
		new_head->next = head;
		ListNode *cur = new_head;
		while(cur){
			if(cur->next && cur->next->val == val){
				cur->next = cur->next->next;
			}else{
			    cur = cur->next;
			}
		}
		return new_head->next;
    }
};