// https://oj.leetcode.com/problems/binary-tree-level-order-traversal-ii/
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > result;
        if (NULL == root) {
            return result;
        }

        std::stack<vector<int> > node_stack;
        std::queue<TreeNode*> node_que_a, node_que_b;
        std::queue<TreeNode*> *node_que_cur = &node_que_a, *node_que_next = &node_que_b;
        node_que_cur->push(root);
        while (!node_que_cur->empty()) {
            vector<int> vec;
            while (!node_que_cur->empty()) {
                TreeNode* top_node = node_que_cur->front();
                vec.push_back(top_node->val);
                if (NULL != top_node->left) {
                    node_que_next->push(top_node->left);
                }
                if (NULL != top_node->right) {
                    node_que_next->push(top_node->right);
                }
                node_que_cur->pop();
            }
            std::swap(node_que_cur, node_que_next);
            node_stack.push(vec);
        }
        while (!node_stack.empty()) {
            result.push_back(node_stack.top());
            node_stack.pop();
        }
        return result;
    }
};
