// https://oj.leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
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
    ListNode *deleteDuplicates(ListNode *head) {
        if (NULL == head) {
            return NULL;
        }
        bool is_del = false;
        ListNode *del_begin = NULL;
        ListNode *del_end = NULL;
        ListNode *cur_node = NULL;
        ListNode *temp_node = NULL;
        ListNode *cur_node_next = head;
        ListNode *cur_head = head;

        while (NULL != cur_node_next) {
            temp_node = cur_node;
            cur_node = cur_node_next;
            cur_node_next = cur_node_next->next;
            if ((NULL != cur_node_next) && (cur_node->val == cur_node_next->val)) {
                if (is_del) {
                    // move del_end
                    del_end = cur_node_next;
                } else {
                    // set del_begin and flag
                    del_begin = temp_node;
                    is_del = true;
                }
            } else {
                if (is_del) {
                    // do del
                    if ((NULL == del_begin) || (del_begin->next == cur_head)) {
                        cur_head = cur_node_next;
                    }
                    if (NULL != del_begin) {
                        del_begin->next = cur_node_next;
                        cur_node = del_begin;
                    }
                    is_del = false;
                }
            }
        }
        return cur_head;
    }
};
