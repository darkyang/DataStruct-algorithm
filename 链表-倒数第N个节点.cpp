/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
    给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
    说明：给定的 n 保证是有效的。
*/

/*
    思考：
    i.链表相关 找第K个节点的问题，第一反应是使用双指针是否能够解决问题。

    ii.由于不仅找到倒数第n个节点，还需要删除，想到找到倒数第n+1个节点，然后删除next节点

    iii.最后考虑边界条件： 1.如果head为空直接返回
                         2.n保证有效，不考虑链表不够长的情况， n=0，刚好需要删除头节点，n<0，是正常情况
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return head;

        ListNode *fast = head;
        ListNode *slow = head;

        while(fast != NULL){
            if(n >= 0){
                n--;
            }else{
                slow = slow->next;
            }
            fast = fast->next;
        }

        if(n == 0) return head->next;
        slow->next = slow->next->next;
        return head;
        }
};