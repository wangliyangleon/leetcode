// https://oj.leetcode.com/problems/remove-nth-node-from-end-of-list/
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (NULL == head){
            return NULL;
        }
        vector<ListNode*> node_vec;
        ListNode *p = head, *p_remove = NULL, *p_remove_before = NULL;
        while (p != NULL) {
            node_vec.push_back(p);
            p = p->next;
        }
        int remove_index = node_vec.size() - n;
        if (0 == remove_index) {
            head = head->next;
        } else {
            p_remove = node_vec.at(remove_index);
            p_remove_before = node_vec.at(remove_index - 1);
            p_remove_before->next = p_remove->next;
        }
        return head;
    }
};
