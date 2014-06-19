// https://oj.leetcode.com/problems/binary-tree-preorder-traversal/
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
    vector<int> preorderTraversal(TreeNode *root) {
        std::vector<int> result;
        if (NULL == root) {
            return result;
        }
        std::stack<TreeNode*> node_stack;
        node_stack.push(root);
        while (!node_stack.empty()) {
            TreeNode* pnode = node_stack.top();
            node_stack.pop();
            result.push_back(pnode->val);
            if (NULL != pnode->right) {
                node_stack.push(pnode->right);
            }
            if (NULL != pnode->left) {
                node_stack.push(pnode->left);
            }
        }
        return result;
    }
};
