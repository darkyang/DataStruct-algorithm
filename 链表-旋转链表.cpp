/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


 /*
    给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
 */

/*
    思路：看到k个， 第一反应双指针找到最后k个节点并将其移动到链表前段
          如果 k 大于链表长度，将整个链表逆序
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = NULL, *pre = head;
        while (pre != NULL) {
            ListNode* t = pre->next;
            pre->next = cur;
            cur = pre;
            pre = t;
        }
        return cur;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0) return head;
        
        ListNode* pre_head = new ListNode(0);
        pre_head->next = head;
        ListNode* front = pre_head;
        ListNode* tail = pre_head;

        int len = 0;
        while(front->next != NULL){
            if(k>0){
                k--;
            }else{
                tail = tail->next;
            }
            front = front->next;
            len++;
        }

        if(k>0){
            return rotateRight(pre_head->next, k%len);
        }else{
            if(tail == pre_head){
                return pre_head->next;
            }
            front->next = pre_head->next;
            pre_head->next = tail->next;
            tail->next = NULL;
        }
        ListNode *tmp = pre_head->next;
        delete pre_head;
        return tmp;
};