// https://oj.leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if (NULL == root) {
            return result;
        }
        bool is_from_right = true;
        vector<TreeNode*> cur_level(1, root);
        vector<TreeNode*> next_level;
        vector<int> cur_result;

        while (!cur_level.empty()) {
            cur_result.clear();
            for (int i = 0; i < cur_level.size(); ++i) {
                cur_result.push_back(cur_level.at(i)->val);
            }

            if (is_from_right) {
                next_level.clear();
                for (int i = cur_level.size() - 1; i >= 0; --i) {
                    TreeNode* pnode = cur_level.at(i);
                    if (NULL != pnode->right) {
                        next_level.push_back(pnode->right);
                    }
                    if (NULL != pnode->left) {
                        next_level.push_back(pnode->left);
                    }
                }
                cur_level.swap(next_level);
            } else {
                next_level.clear();
                // for (int i = 0; i < cur_level.size(); ++i) {
                for (int i = cur_level.size() - 1; i >= 0; --i) {
                    TreeNode* pnode = cur_level.at(i);
                    if (NULL != pnode->left) {
                        next_level.push_back(pnode->left);
                    }
                    if (NULL != pnode->right) {
                        next_level.push_back(pnode->right);
                    }
                }
                cur_level.swap(next_level);
            }
            result.push_back(cur_result);
            is_from_right = !is_from_right;
            }
            return result;
        }
    };
