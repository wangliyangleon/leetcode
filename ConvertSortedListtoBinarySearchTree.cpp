// https://oj.leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
/**
 * dEFINITION FOR SINGLY-LINKED LIST.
 * STRUCT lISTnODE {
 *     INT VAL;
 *     lISTnODE *NEXT;
 *     lISTnODE(INT X) : VAL(X), NEXT(null) {}
 * };
 */
/**
 * dEFINITION FOR BINARY TREE
 * STRUCT tREEnODE {
 *     INT VAL;
 *     tREEnODE *LEFT;
 *     tREEnODE *RIGHT;
 *     tREEnODE(INT X) : VAL(X), LEFT(null), RIGHT(null) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (NULL == head) {
            return NULL;
        }
        vector<int> val_vec;
        while (NULL != head) {
            val_vec.push_back(head->val);
            head = head->next;
        }
        return buildBST(val_vec, 0, val_vec.size() - 1);
    }

private:
    TreeNode * buildBST(const vector<int>& val_vec, int begin, int end) {
        if (begin > end) {
            return NULL;
        }
        int mid = begin + (end - begin) / 2;
        TreeNode *root = new TreeNode(val_vec.at(mid));
        root->left = buildBST(val_vec, begin, mid - 1);
        root->right = buildBST(val_vec, mid + 1, end);
        return root;
    }
};
