// https://oj.leetcode.com/problems/insertion-sort-list/
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (NULL == head) {
            return NULL;
        }
        ListNode *cur_head = head;
        ListNode *insert_pos_node = head;
        ListNode *insert_pos_pre = NULL;
        ListNode *cur_node = head->next;
        ListNode *cur_node_pre = head;
        ListNode *next_node = head->next;
        while (next_node != NULL) {

            cur_node_pre = head;
            cur_node = next_node;
            while (cur_node_pre->next != cur_node) {
                cur_node_pre = cur_node_pre->next;
            }
            next_node = next_node->next;

            insert_pos_node = cur_head;
            insert_pos_pre = NULL;
            while ((insert_pos_node != cur_node) && (insert_pos_node->val <= cur_node->val)) {
                insert_pos_pre = insert_pos_node;
                insert_pos_node = insert_pos_node->next;
            }
            if (insert_pos_node == cur_head) {
                cur_head = cur_node;
            }
            if (insert_pos_node != cur_node) {
                insertNode(cur_node_pre, cur_node, insert_pos_pre, insert_pos_node);
            }
        }
        return cur_head;
    }

private:
    void insertNode(ListNode *pnode_pre, ListNode *pnode, ListNode *ppos_pre, ListNode *ppos) {
        if (NULL == pnode_pre || NULL == pnode || NULL == ppos) {
            return;
        }
        pnode_pre->next = pnode->next;
        pnode->next = ppos;
        if (NULL != ppos_pre) {
            ppos_pre->next = pnode;
        }
    }
};
