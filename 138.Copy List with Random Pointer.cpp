/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL) return NULL;
        RandomListNode * new_head = head;
        //复制链表元素
        while(new_head != NULL){
            RandomListNode * node = new RandomListNode(new_head -> label);
            node -> next = new_head -> next;
            new_head -> next = node;
            new_head = node -> next;
        }
        //调整新链表元素的random
        new_head = head;
        while(new_head != NULL && new_head -> next != NULL){
            if(new_head -> random != NULL){
                new_head -> next -> random = new_head -> random -> next;
            }
            new_head = new_head -> next -> next;
        }
        //断开链表,首先将拷贝节点前面的元素指向它后面的元素。然后再将这个拷贝节点往后面跳一个
        new_head = head;
        RandomListNode* cur = head -> next;
        RandomListNode* copy = cur;
        while(new_head != NULL && copy != NULL){
            new_head -> next = copy -> next;
            new_head = new_head -> next;
            if(copy -> next){
                copy -> next = copy -> next -> next;
            }
            copy = copy -> next;
        }
        return cur;
    }
};