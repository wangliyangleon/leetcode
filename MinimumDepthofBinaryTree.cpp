// https://oj.leetcode.com/problems/minimum-depth-of-binary-tree/
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
    int minDepth(TreeNode *root) {
        if (NULL == root) {
            return 0;
        } else if (NULL == root->left && NULL == root->right) {
            return 1;
        } else if (NULL == root->left) {
            return minDepth(root->right) + 1;
        } else if (NULL == root->right) {
            return minDepth(root->left) + 1;
        } else {
            return min(minDepth(root->left), minDepth(root->right)) + 1;
        }
    }
};
