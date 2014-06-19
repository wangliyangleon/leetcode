// https://oj.leetcode.com/problems/linked-list-cycle/
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
    bool hasCycle(ListNode *head) {
        if (NULL == head || NULL == head->next) {
            return false;
        }
        ListNode *tmp_node1 = head, *tmp_node2 = head;
        for (;;) {
            if (NULL == tmp_node1 || NULL == tmp_node2 || NULL == tmp_node2->next) {
                return false;
            }
            tmp_node1 = tmp_node1->next;
            tmp_node2 = tmp_node2->next->next;
            if (tmp_node1 == tmp_node2) {
                return true;
            }
        }
    }
};
