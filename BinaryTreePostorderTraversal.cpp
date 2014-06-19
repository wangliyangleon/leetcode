// https://oj.leetcode.com/problems/binary-tree-postorder-traversal/
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
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode*> node_stack;
        stack<int> flag_stack;
        vector<int> result;
        if (NULL == root) {
            return result;
        }

        TreeNode* pnode = root;
        int flag = 0;
        while (NULL != pnode) {
            node_stack.push(pnode);
            flag_stack.push(0);
            pnode = pnode->left;
        }

        while (!node_stack.empty()) {
            pnode = node_stack.top();
            flag = flag_stack.top();
            if ((NULL == pnode->right) || 1 == flag) {
                node_stack.pop();
                flag_stack.pop();
                result.push_back(pnode->val);
            } else if (NULL != pnode->right && 0 == flag) {
                flag_stack.pop();
                flag_stack.push(1);
                pnode = pnode->right;
                while (NULL != pnode) {
                    node_stack.push(pnode);
                    flag_stack.push(0);
                    pnode = pnode->left;
                }
            }
        }
        return result;
    }
};
