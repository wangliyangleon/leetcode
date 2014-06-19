// https://oj.leetcode.com/problems/swap-nodes-in-pairs/
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
    ListNode *swapPairs(ListNode *head) {
        if (NULL == head || NULL == head->next) {
            return head;
        }
        ListNode *cur_node = head, *tmp_node = NULL, *pre_node = NULL, *root_node = head->next;
        while (NULL != cur_node && NULL != cur_node->next) {
            tmp_node = cur_node->next;
            cur_node->next = tmp_node->next;
            tmp_node->next = cur_node;
            if (NULL != pre_node) {
                pre_node->next = tmp_node;
            }
            pre_node = cur_node;
            cur_node = cur_node->next;
        }
        return root_node;
    }
};
