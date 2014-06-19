// https://oj.leetcode.com/problems/binary-tree-level-order-traversal/
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        vector<int> cur_line;
        queue<TreeNode*> node_queue;
        if (NULL == root) {
            return result;
        }

        node_queue.push(root);
        node_queue.push(NULL);
        while (!node_queue.empty()) {
            TreeNode* front_node = node_queue.front();
            if (NULL ==  front_node) {
                result.push_back(cur_line);
                cur_line.clear();
                node_queue.pop();
                if (!node_queue.empty()) {
                    node_queue.push(NULL);
                }
            } else {
                cur_line.push_back(front_node->val);
                if (NULL != front_node->left) {
                    node_queue.push(front_node->left);
                }
                if (NULL != front_node->right) {
                    node_queue.push(front_node->right);
                }
                node_queue.pop();
            }
        }
        return result;
    }
};
