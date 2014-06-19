// https://oj.leetcode.com/problems/symmetric-tree/
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
    bool isSymmetric(TreeNode *root) {
        if (NULL == root) {
            return true;
        }
        std::stack<TreeNode*> left_stack, right_stack;
        if (NULL != root->left) {
            left_stack.push(root->left);
        }
        if (NULL != root->right) {
            right_stack.push(root->right);
        }
        for (;;) {
            if (left_stack.empty() && right_stack.empty()) {
                return true;
            }
            if (left_stack.empty() || right_stack.empty()) {
                return false;
            }
            TreeNode* pleft = left_stack.top();
            TreeNode* pright = right_stack.top();
            if ((pleft->val != pright->val) ||
                    (NULL == pleft->left && NULL != pright->right) ||
                    (NULL != pleft->left && NULL == pright->right) ||
                    (NULL == pleft->right && NULL != pright->left) ||
                    (NULL != pleft->right && NULL == pright->left)) {
                return false;
            }
            left_stack.pop();
            right_stack.pop();
            if (NULL != pleft->left) {
                left_stack.push(pleft->left);
            }
            if (NULL != pleft->right) {
                left_stack.push(pleft->right);
            }
            if (NULL != pright->right) {
                right_stack.push(pright->right);
            }
            if (NULL != pright->left) {
                right_stack.push(pright->left);
            }
        }
    }
};
