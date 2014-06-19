// https://oj.leetcode.com/problems/linked-list-cycle-ii/
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
    ListNode *detectCycle(ListNode *head) {
        if (NULL == head || NULL == head->next) {
            return NULL;
        }
        ListNode *pnode1 = head, *pnode2 = head->next->next, *begin_node = head;
        for (;;) {
            if (NULL == pnode2 || NULL == pnode2->next) {
                return NULL;
            }
            if (pnode1 == pnode2) {
                break;
            }
            pnode1 = pnode1->next;
            pnode2 = pnode2->next->next;
        }
        for (;;) {
            pnode2 = pnode1;
            do {
                if (begin_node == pnode2) {
                    return begin_node;
                }
                pnode2 = pnode2->next;
            } while (pnode2 != pnode1);
            begin_node = begin_node->next;
        } // 这么解有点太暴力了。。。。。。
    }
};
