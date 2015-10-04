/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
    ListNode* swapPairs(ListNode* head) {
        if(!head) return NULL;
		ListNode *temp = new ListNode(0);
		ListNode *result = head;
		while(head && head->next){
			temp->val = head->val;
			head->val = head->next->val;
			head->next->val = temp->val;
			head = head->next->next;
		}
		return result;
    }
};