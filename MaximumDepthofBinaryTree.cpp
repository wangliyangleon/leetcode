// https://oj.leetcode.com/problems/maximum-depth-of-binary-tree/
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
    int maxDepth(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return tryDepth(root);
    }

private:
    int tryDepth(TreeNode* node) {
        if (NULL == node) {
            return 0;
        }
        else {
            return std::max<int>(tryDepth(node->left), tryDepth(node->right)) + 1;
        }
    }
};
