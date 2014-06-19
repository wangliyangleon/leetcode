// https://oj.leetcode.com/problems/binary-tree-inorder-traversal/
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
    vector<int> inorderTraversal(TreeNode *root) {
        std::vector<int> result;
        if (NULL == root) {
            return result;
        }
        std::stack<TreeNode*> node_stack;
        TreeNode* pnode = root;
        while (pnode != NULL) {
            node_stack.push(pnode);
            pnode = pnode->left;
        }
        while (!node_stack.empty()) {
            pnode = node_stack.top();
            node_stack.pop();
            result.push_back(pnode->val);
            if (NULL != pnode->right) {
                pnode = pnode->right;
                while (pnode != NULL) {
                    node_stack.push(pnode);
                    pnode = pnode->left;
                }
            }
        }
        return result;
    }
};
