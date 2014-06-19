// https://oj.leetcode.com/problems/merge-k-sorted-lists/
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode* new_head = NULL, *cur_tail = NULL;
        vector<ListNode *> cmp_vec;

        for (int i = 0; i < lists.size(); ++i) {
            if (lists.at(i) != NULL) {
                cmp_vec.push_back(lists.at(i));
            }
        }

        ListNode* min_node = NULL;
        int min_val = INT_MAX, min_idx = -1;
        while (!cmp_vec.empty()) {
            min_node = NULL;
            min_val = INT_MAX;
            min_idx = -1;
            for (int i = 0; i < cmp_vec.size(); ++i) {
                if (cmp_vec.at(i)->val < min_val) {
                    min_val = cmp_vec.at(i)->val;
                    min_idx = i;
                    min_node = cmp_vec.at(i);
                }
            }
            if (NULL == new_head) {
                new_head = cur_tail = min_node;
            } else {
                cur_tail->next = min_node;
                cur_tail = min_node;
            }
            if (NULL == min_node->next) {
                cmp_vec.erase(cmp_vec.begin() + min_idx);
            } else {
                cmp_vec[min_idx] = min_node->next;
            }
        }
        if (NULL != cur_tail) {
            cur_tail->next = NULL;
        }
        return new_head;
    }
};
