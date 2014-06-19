// https://oj.leetcode.com/problems/reverse-nodes-in-k-group/
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (2 > k || NULL == head) {
            return head;
        }
        int rev_grp_cnt = 0, tmpk = k - 1;
        ListNode* pnode = head;
        while (pnode != NULL) {
            if (0 == tmpk) {
                ++rev_grp_cnt;
                tmpk = k - 1;
            } else {
                --tmpk;
            }
            pnode = pnode->next;
        }

        pnode = head;
        ListNode *ppre = NULL, *pn = head->next;
        ListNode *pnn = (NULL != pn ? pn->next : NULL);
        ListNode *pghead = NULL, *pgtail = NULL, *pnhead = head;
        for (int i = 0; i < rev_grp_cnt; ++i) {
            pgtail = pnode;
            for (int j = 0; j < k - 1; ++j) {
                if (NULL != pn) {
                    pn->next = pnode;
                }
                pnode = pn;
                pn = pnn;
                pnn = (NULL != pn ? pn->next : NULL);
            }
            pghead = pnode;
            if (NULL != ppre) {
                ppre->next = pnode;
            } else {
                pnhead = pnode;
            }
            ppre = pgtail;
            pnode = pn;
            pn = pnn;
            pnn = (NULL != pn ? pn->next : NULL);
        }
        if (NULL != ppre) {
            ppre->next = pnode;
        }

        return pnhead;
    }
};

