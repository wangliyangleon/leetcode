// https://oj.leetcode.com/problems/path-sum/
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
    bool hasPathSum(TreeNode *root, int sum) {
        if (NULL == root) {
            return false;
        }
        if (NULL == root->left && NULL == root->right) {
            return sum == root->val;
        } else if (NULL == root->left) {
            return hasPathSum(root->right, sum - root->val);
        } else if (NULL == root->right) {
            return hasPathSum(root->left, sum - root->val);
        } else {
            return hasPathSum(root->right, sum - root->val) ||
                hasPathSum(root->left, sum - root->val);
        }
    }
};
