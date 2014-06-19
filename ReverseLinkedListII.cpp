// https://oj.leetcode.com/problems/reverse-linked-list-ii/
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m == n) {
            return head;
        } else if (m > n) {
            int t = m;
        }

        ListNode *pm = NULL, *pn = NULL, *pt = head, *pm_before = NULL;
        vector<ListNode *> revert_node_vec;
        for (int i = 1; i <= n; ++i) {
            if (NULL == pt) {
                return head;
            }
            if (m - 1 == i) {
                pm_before = pt;
            }
            if (m == i) {
                pm = pt;
            }
            if (n == i) {
                pn = pt;
            }
            if (i >= m && i <= n) {
                revert_node_vec.push_back(pt);
            }
            pt = pt->next;
        }

        // a b c d e f g
        //   |     |
        // a e d c b f g
        if (NULL != pm_before) {
            pm_before->next = pn;
        } else {
            head = pn;
        }
        pm->next = pn->next;
        for (int i = revert_node_vec.size() - 1; i > 0; --i) {
            revert_node_vec.at(i)->next = revert_node_vec.at(i - 1);
        }
        return head;
    }
};
