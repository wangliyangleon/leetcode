// https://oj.leetcode.com/problems/rotate-list/
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
    ListNode *rotateRight(ListNode *head, int k) {
        if (0 == k || NULL == head || NULL == head->next) {
            return head;
        }
        ListNode * new_head = NULL;
        ListNode * pnode = head;
        stack<ListNode *> node_stack;
        int list_size = 0;

        while (NULL != pnode) {
            ++list_size;
            node_stack.push(pnode);
            pnode = pnode->next;
        }
        pnode = node_stack.top();
        k %= list_size;
        if (0 == k) {
            return head;
        }

        while ((k--) && (!node_stack.empty())) {
            new_head = node_stack.top();
            node_stack.pop();
        }
        if (!node_stack.empty()) {
            pnode->next = head;
            node_stack.top()->next = NULL;
        }
        return new_head;
    }
}; 
