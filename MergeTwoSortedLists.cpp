// https://oj.leetcode.com/problems/merge-two-sorted-lists/
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (NULL == l1) {
            return l2;
        }
        if (NULL == l2) {
            return l1;
        }
        ListNode* host = ((l1->val < l2->val) ? l1 : l2);
        ListNode* guest = ((l1->val < l2->val) ? l2 : l1);
        ListNode* hook = host;
        for (;;) {
            if (NULL == guest) {
                break;
            }
            if (NULL == hook->next) {
                hook->next = guest;
                break;
            }
            while ((NULL != hook->next) && (hook->next->val < guest->val)) {
                hook = hook->next;
            }
            if (NULL != hook->next) {
                ListNode* ptmp = hook->next;
                hook->next = guest;
                guest = guest->next;
                hook->next->next = ptmp;
            }
        }
        return host;
    }
};
