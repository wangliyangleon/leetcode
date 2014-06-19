// https://oj.leetcode.com/problems/add-two-numbers/
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (NULL == l1) {
            return l2;
        } else if (NULL == l2) {
            return l1;
        }

        ListNode *pl1 = l1, *pl2 = l2, *head = NULL, *tail = NULL;
        int sign = 0, cur_val = 0;
        while (pl1 != NULL && pl2 != NULL) {
            cur_val = pl1->val + pl2->val + sign;
            sign = cur_val / 10;
            ListNode *new_node = new ListNode(cur_val % 10);
            if (NULL == head) {
                tail = head = new_node;
            } else {
                tail->next = new_node;
                tail = new_node;
            }
            pl1 = pl1->next;
            pl2 = pl2->next;
        }

        ListNode *remain = (NULL == pl1 ? pl2 : pl1);
        while (remain != NULL) {
            cur_val = remain->val + sign;
            sign = cur_val / 10;
            ListNode *new_node = new ListNode(cur_val % 10);
            tail->next = new_node;
            tail = new_node;
            remain = remain->next;
        }

        if (1 == sign) {
            ListNode *new_node = new ListNode(1);
            tail->next = new_node;
            tail = new_node;
        }

        return head;
    }
};
