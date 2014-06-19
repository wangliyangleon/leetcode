// https://oj.leetcode.com/problems/remove-duplicates-from-sorted-list/
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
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (NULL == head) {
            return NULL;
        }
        std::unordered_set<int> val_set;
        for (ListNode *p = head, *pre = head; p != NULL;) {
            if (val_set.end() == val_set.find(p->val)) {
                val_set.insert(p->val);
                pre = p;
                p = p->next;
            } else {
                // if neccessary, save and del p
                if (head == p) {
                    p = pre = head = head->next;
                } else {
                    p = pre->next = p->next;
                }
            }
        }
        return head;
    }
};
