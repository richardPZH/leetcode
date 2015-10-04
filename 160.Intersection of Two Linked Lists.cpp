/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 �� a2
                   �K
                     c1 �� c2 �� c3
                   �J            
B:     b1 �� b2 �� b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
		int LenA = 0, LenB = 0;
		ListNode *curA = headA;
		ListNode *curB = headB;

		while(headA){
			LenA++;
			headA = headA->next;
		}
		while(headB){
			LenB++;
			headB = headB->next;
		}

		int diff = abs(LenA - LenB);
		if(LenA > LenB){
			while(diff--){
				curA = curA->next;
			}
		}
		if(LenB > LenA){
			while(diff--){
				curB = curB->next;
			}
		}

		while(curA){
			if(curA->val != curB->val){
				curA = curA->next;
				curB = curB->next;
			}else{
				return curA;
			}
		}
		return NULL;
    }
};