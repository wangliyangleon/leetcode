// https://oj.leetcode.com/problems/binary-tree-maximum-path-sum/
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
    int maxPathSum(TreeNode *root) {
        if (NULL == root) {
            return 0;
        }
        _result = INT_MIN;
        _trace(root);
        return _result;
    }

private:
    void _trace(TreeNode *pnode) {
        if (NULL == pnode) {
            return;
        }
        int left_val = pnode->val, right_val = pnode->val;
        if (NULL != pnode->left) {
            _trace(pnode->left);
            left_val = max(pnode->val, pnode->val + pnode->left->val);
        }
        if (NULL != pnode->right) {
            _trace(pnode->right);
            right_val = max(pnode->val, pnode->val + pnode->right->val);
        }
        int cur_val = max(max(left_val, right_val), left_val + right_val - pnode->val);
        if (cur_val > _result) {
            _result = cur_val;
        }
        pnode->val = max(left_val, right_val);
    }

    int _result;
};
