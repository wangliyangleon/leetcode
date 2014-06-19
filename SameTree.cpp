// https://oj.leetcode.com/problems/same-tree/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool checkNode(const TreeNode* n1, const TreeNode* n2) {
        if (NULL == n1 && NULL == n2) {
            return true;
        }
        if ((NULL == n1 || NULL == n2) || (n1->val != n2->val)) {
            return false;
        }
        return checkNode(n1->left, n2->left) && checkNode(n1->right, n2->right);
    }
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return checkNode(p, q);
    }
};
