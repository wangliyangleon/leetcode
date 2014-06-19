// https://oj.leetcode.com/problems/partition-list/
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
    ListNode *partition(ListNode *head, int x) {
        ListNode *pnode = head, *pos = NULL, *pbefore = NULL, *pcur = NULL;
        while (pnode != NULL) {
            pbefore = pcur;
            pcur = pnode;
            if (pcur->val < x) {
                head = insert(head, pos, pcur, pbefore);
                if (NULL == pos) {
                    pos = head;
                } else {
                    pos = pos->next;
                }
            }
            pnode = pnode->next;
        }
        return head;
    }
private:
    ListNode * insert(ListNode *head, ListNode *pos, ListNode *to_insert, ListNode *insert_before) {
        if (NULL != insert_before) {
            insert_before->next = to_insert->next;
            if (NULL == pos) {
                to_insert->next = head;
                head = to_insert;
            } else {
                to_insert->next = pos->next;
                pos->next = to_insert;
            }
        }
        return head;
    }
};
