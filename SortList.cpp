// https://oj.leetcode.com/problems/sort-list/
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
    void mergeList(ListNode *left, int left_len, ListNode *right, int right_len, ListNode*& head, ListNode*& tail) {
        if (0 == left_len) {
            head = right;
            while (--right_len) {
                right = right->next;
            }
            tail = right;
        } else if (0 == right_len) {
            while (--left_len) {
                left = left->next;
            }
            tail = left;
        } else {
            head = tail = NULL;
            while ((left_len > 0) && (right_len > 0)) {
                if (left->val < right->val) {
                    if (NULL == head) {
                        head = tail = left;
                    } else {
                        tail->next = left;
                        tail = left;
                    }
                    left = left->next;
                    --left_len;
                } else {
                    if (NULL == head) {
                        head = tail = right;
                    } else {
                        tail->next = right;
                        tail = right;
                    }
                    right = right->next;
                    --right_len;
                }
            }
            while (left_len--) {
                tail->next = left;
                tail = left;
                left = left->next;
            }
            while (right_len--) {
                tail->next = right;
                tail = right;
                right = right->next;
            }
        }
    }

    void mergeSort(ListNode* begin, int len, ListNode* pre, ListNode* post, ListNode*& head, ListNode*& tail) {
        if (len <= 1) {
            head = tail = begin;
            return;
        }
        int left_len = (len + 1) / 2;
        int right_len = len - left_len;

        ListNode *mid = begin, *newhead_left = NULL, *newtail_left = NULL, *newhead_right = NULL, *newtail_right = NULL;
        for (int i = 0; i < left_len; ++i) {
            mid = mid->next;
        }
        mergeSort(begin, left_len, pre, mid, newhead_left, newtail_left);
        mergeSort(mid, right_len, newtail_left, post, newhead_right, newtail_right);
        mergeList(newhead_left, left_len, newhead_right, right_len, head, tail);
        if (NULL != pre) {
            pre->next = head;
        }
        tail->next = post;
    }

    ListNode *sortList(ListNode *head) {
        if (NULL == head) {
            return NULL;
        }
        int len = 1;
        ListNode *pnode = head;
        while (NULL != pnode->next) {
            ++len;
            pnode = pnode->next;
        }
        mergeSort(head, len, NULL, NULL, head, pnode);
        return head;
    }
};
