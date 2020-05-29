/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


/*
    给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
    你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
*/

/*
    思路1： 借助辅助空间，长度为n的数组，将链表所有节点加入数组，再从数组中取出节点构成新的链表，时间复杂度O（n+n） 空间复杂度（n）

    思路2： 双指针遍历，添加辅助头节点，双指针相隔一个节点，跳跃式前进

    思路3： 思路2的递归

    偶数个节点正常进行，奇数个节点则最后一个节点不再交换。
*/


class Solution {
public:
    //思路2：
    ListNode* swapPairs(ListNode* head) {
        ListNode *pre_head = new ListNode(0);
        pre_head->next = head;
        ListNode *front = pre_head;
        ListNode *tail = pre_head;

        while(front->next->next != NULL){
            front = front->next->next;

            tail->next->next = front->next;
            front->next = tail->next;
            tail->next = front;

            front = front->next;
            tail = front;
        }
        ListNode *tmp = pre_head->next;
        delete pre_head;
        return tmp;
    }

    //思路3： 三指针
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *tail = head->next;
        ListNode *front = tail->next;
        tail->next = head;

        head->next = swapPairs(front);
        return tail;
    }
};