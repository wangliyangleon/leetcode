// https://oj.leetcode.com/problems/reorder-list/
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
    void reorderList(ListNode *head) {
        if (NULL == head) {
            return;
        }

        ListNode *phead = head, *ptemp = head;
        vector<ListNode *> ori_order_vec;
        while (NULL != ptemp) {
            ori_order_vec.push_back(ptemp);
            ptemp = ptemp->next;
        }

        int ncnt = ori_order_vec.size();
        for (int i = 0; i < ncnt / 2; ++i) {
            ListNode *pbefore = ori_order_vec.at(i);
            ListNode *pafter = ori_order_vec.at(ncnt - i - 1);
            pafter->next = pbefore->next;
            pbefore->next = pafter;
        }
        ori_order_vec.at(ncnt / 2)->next = NULL;
    }   
};  
