// https://oj.leetcode.com/problems/flatten-binary-tree-to-linked-list/
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
    void flatten(TreeNode *root) {
        if (NULL == root) {
            return;
        }
        stack<TreeNode *> pnode_stack;
        pnode_stack.push(root);
        while (!pnode_stack.empty()) {
            TreeNode *pnode = pnode_stack.top();
            pnode_stack.pop();
            if (NULL != pnode->right) {
                pnode_stack.push(pnode->right);
            }
            if (NULL != pnode->left) {
                pnode_stack.push(pnode->left);
            }
            pnode->left = NULL;
            pnode->right = pnode_stack.empty() ? NULL : pnode_stack.top();
        }
    }
};
