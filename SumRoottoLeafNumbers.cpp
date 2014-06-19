// https://oj.leetcode.com/problems/sum-root-to-leaf-numbers/
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
    int sumNumbers(TreeNode *root) {
        if (NULL == root) {
            return 0;
        }
        _try_path(root, 0);
        return _result;
    }
private:
    void _try_path(TreeNode* pnode, int cur_val) {
        cur_val *= 10;
        cur_val += pnode->val;
        if (NULL == pnode->left && NULL == pnode->right) {
            _result += cur_val;
        } else {
            if (NULL != pnode->left) {
                _try_path(pnode->left, cur_val);
            }
            if (NULL != pnode->right) {
                _try_path(pnode->right, cur_val);
            }
        }
    }
    int _result;
};
