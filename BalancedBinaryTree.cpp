// https://oj.leetcode.com/problems/balanced-binary-tree/
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
    bool isBalanced(TreeNode *root) {
        return (-1 != balancedDepth(root));
    }

private:
    int balancedDepth(TreeNode* node) {
        if (NULL == node) {
            return 0;
        }

        int depth_left = 0, depth_right = 0;
        if (NULL != node->left) {
            depth_left = balancedDepth(node->left);
        }
        if (NULL != node->right) {
            depth_right = balancedDepth(node->right);
        }
        if (-1 == depth_left || -1 == depth_right) {
            return -1;
        } else if ((depth_left - depth_right) > 1 ||
                (depth_left - depth_right) < -1) {
            return -1;
        } else {
            return std::max(depth_left, depth_right) + 1;
        }
    }
};
