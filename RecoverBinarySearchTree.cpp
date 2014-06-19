// https://oj.leetcode.com/problems/recover-binary-search-tree/
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
    void recoverTree(TreeNode *root) {
        if (NULL == root) {
            return;
        }
        vector<TreeNode *> bad_nodes;
        vector<int> bad_vals;
        stack<TreeNode *> node_stack;
        TreeNode *pnode = root;
        TreeNode *last_node = NULL;

        while (NULL != pnode) {
            node_stack.push(pnode);
            pnode = pnode->left;
        }

        while (!node_stack.empty()) {
            pnode = node_stack.top();
            if (NULL != last_node) { 
                if (last_node->val > pnode->val) {
                    bad_nodes.push_back(last_node);
                    bad_nodes.push_back(pnode);
                    bad_vals.push_back(last_node->val);
                    bad_vals.push_back(pnode->val);
                }
            }
            last_node = pnode;
            node_stack.pop();
            if (NULL != pnode->right) {
                pnode = pnode->right;
                while (NULL != pnode) {
                    node_stack.push(pnode);
                    pnode = pnode->left;
                }
            }
        }

        sort(bad_vals.begin(), bad_vals.end());
        for (int i = 0; i < bad_vals.size(); ++i) {
            bad_nodes.at(i)->val = bad_vals.at(i);
        }
    }
};
